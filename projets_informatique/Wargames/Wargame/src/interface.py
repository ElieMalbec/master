# -*- coding: utf-8 -*-
"""Fichier contenants les classes nécessaires à l'interface graphique, la fenêtre principale est la dernère classe
du fichier et utilise les autres pour fonctionner. De plus, cette interface à besoin de créer des Armee via la classe
Armee. Une armée est composée de Troupes issues de la classe Troupe.
La confrontation est gérée avec le module moteurCombat, l'optimisation des armées via le module optimisateur.
D'autres bibliothèques sont utilisées comme celle de tkinter pour l'affichage graphique, json pour la sérialisation
d'objets dans des fichiers ou encore le module copy pour passer des copies d'armée à se confronter."""

import copy
import datetime
import json
import os.path
import time
from threading import Thread
from tkinter import ttk
from tkinter.filedialog import *
from tkinter.messagebox import *

# Import des bibliothèques et modules nécessaires pour le fonctionnement du programme
import Armee as A
import Troupe as Tr
import moteurCombat as Mc
import optimisateur as O
from PIL import Image as PILIMAGE

colorquit = '#e35442'


class MonScale(Scale):
    """Class MonScale héritant de l'object Scale, permet la création des échelles de choix du nombre d'unités pour
    chaque troupe. Elle prend en paramètre le nom de la troupe, une variable si une valeur est déjà fixée et un
    paramètre state pour l'état du curseur. Pour laisser l'utilisateur choisir : le state est sur 'normal' sinon c'est
    'disabled'"""

    def __init__(self, fen, nom, armee, var=0, state='normal'):
        """Nous initialisons notre scale, nous lui passons en paramètre une variable InvVar qui prend soit la valeur par 
        défaut soit la nouvelle valeur donnée en paramètre. Les scales sont horizontaux et portent le nom donné par
        'nom'
        La limite max du nombre d'unité est fixée à 200. Cette valeur pourra être descendue avec les limites
        Le paramètre armée passe une armée pour laquelle il ne faut pas dépasser le nombre de points : exemple, si nous
        choisissons l'armée du joueur solo, il ne faut pas que le nombre de points dépasse celui contenu dans l'armée de
        l'optimisateur. Nous lui donnons donc l'armée de l'optimisateur en paramètre"""
        self.fen = fen
        self.var = IntVar()
        self.var.set(var)
        self.armee = armee
        self.pt_armee = armee.COUT
        Scale.__init__(self, fen, command=lambda x=0: self.nouvelle_valeur(nom), variable=self.var, from_=0, to=200,
                       orient='horizontal', resolution=1, length=200, label=nom, state=state)

    def nouvelle_valeur(self, nom):
        """A chaque changement de valeur de la variable correspondante à un curseur, nous attribuons cette valeur dans
        le dictionnaire de la classe MaFen troupes.
        Création d'une armée avec pour effectif celui contenu dans le dictionnaire Mafen.troupes.
        Nous récupérons la valeur du coût total de l'armée pour le mettre dans le label de sortie de la Toplevel.
        Puis les totaux concernant les pv, pa, df, vit généraux sont affichées dans un autre label
        Si le nombre de points de l'armée dépasse celui de l'armée passée en en paramètre du init (pt_armee), alors
        le label points devient rouge, sinon il prend la couleur de base"""
        MaFen.troupes[nom] = self.var.get()
        a = A.Armee()
        a.former_armee_simple(MaFen.troupes)

        string = str(a.COUT) + " points"
        if self.pt_armee != 0:
            # Nous testons si une limite de points est en vigueur (!=0), si oui nous affichons ce maximum
            string = string + ". Maximum de points : " + str(self.pt_armee)
            if a.COUT > self.pt_armee:
                # Si le coût total de l'armée est supérieur à celui contenu dans la limite le label devient rouge
                self.fen.fen.selection.sortie.configure(bg='red')
            else:
                self.fen.fen.selection.sortie.configure(bg='#D9D9D9')
        self.fen.fen.labelSortie.set(string)

        # Nous parcourons les limites de l'armée, et nous les mettons en vigueur en changeant la valeur maximale des
        # scales correspondants. Si la limite n'est pas à zéro, nous ne changeons pas le _to. Si la limite est à 0, nous
        # désactivons le label pour éviter les erreurs de Tkinter qui ajoute un même si nous ne pouvons aller prendre
        # cette valeur avec le curseur.
        for elem in a.limites:
            self.fen.fen.scales[elem].configure(to=a.limites[elem])
            if a.limites[elem] == 0:
                self.fen.fen.scales[elem].configure(state="disabled")
            else:
                self.fen.fen.scales[elem].configure(state="normal")

        # Les totaux de l'armée en cours sont affichés dans le label stats avec pour variable statsVar
        str_stats = "PV : " + str(a.PV) + "    PA : " + str(a.PA) + "    DF : " + str(a.DF) + "    VIT : " + str(a.VIT)
        self.fen.fen.statsVar.set(str_stats)


class LabelAffichage(Label):
    """Classe de création du Label d'affichage des armées héritant de l'object Label"""

    def __init__(self, fen, **kw):
        """Constructeur de la classe, le texte est passé en paramètre dans **kw; permet d'éviter de spécifier les
        paramètres de marges et de largeur, la couleur est donnée depuis l'appel"""
        self.fen = fen
        Label.__init__(self, self.fen, width=50, padx=3, pady=3, **kw)


class SelectionTroupes(Frame):
    """Classe pour la sélection des troupes, elle permet de mettre l'ensemble des scales dans une frame pour la grid
    ensuite, cette classe évite de répéter cette manipulation trois fois dans le code global. Les boutons appelent
    cependant les méthodes qui appartiennent à leur fenêtre mère pour faire certaines opérations. Les méthodes des
    classes mères portent donc les mêmes noms.
    Des arguments supplémentaires peuvent être passés : notamment alea qui ajoute un bouton de génération d'armée
    aléatoire en fonction d'un nombre de points donné par l'utilisateur. Mais aussi recup pour récupérer l'armée
    courante contenue dans les armées des joueurs pour la classe EnregistrerArmee"""

    def __init__(self, fen, armee, **kwargs):
        """Création de la frame"""
        Frame.__init__(self, fen)
        self.grid()
        self.fen = fen
        self.fen.bind("<Escape>", self.fen.quitter_top_level)
        self.fen.bind("<Return>", self.fen.validate)
        self.recupArmee = IntVar()
        self.armee = A.Armee()
        self.armeeRecup = A.Armee()
        self.reponse_points = StringVar()

        self.fen.fen.reinitialiser_troupes()

        self.entree_points = Entry(self, textvariable=self.reponse_points, width=30)
        self.button_validate_aleatoire = Button(self)
        self.button_validate_aleatoire = Button(self)
        self.quitter_aleatoire = Button(self)

        # Nous mettons tous les scales dans un dictionnaire pour ensuite accèder à la variable var dans les méthodes
        for j, elem in enumerate(MaFen.troupes):
            j = j + 1
            if j <= 5:
                self.fen.scales[elem] = MonScale(self, elem, armee)
                self.fen.scales[elem].grid(column=0, row=j - 1, sticky='EW')
            elif 5 < j <= 10:
                self.fen.scales[elem] = MonScale(self, elem, armee)
                self.fen.scales[elem].grid(column=1, row=j - 6, sticky='EW')
            elif 10 < j <= 15:
                self.fen.scales[elem] = MonScale(self, elem, armee)
                self.fen.scales[elem].grid(column=2, row=j - 11, sticky='EW')
            elif 15 < j <= 20:
                self.fen.scales[elem] = MonScale(self, elem, armee)
                self.fen.scales[elem].grid(column=3, row=j - 16, sticky='EW')
            else:
                self.fen.scales[elem] = MonScale(self, elem, armee)
                self.fen.scales[elem].grid(column=4, row=j - 21, sticky='EW')

        # Certaines carac sont bloquées directement lors de la création pour éviter les erreurs liées à Tkinter
        self.fen.scales['Catapulte'].configure(state="disabled")
        self.fen.scales['Chariot'].configure(state="disabled")
        self.fen.scales['ElephantDeCombat'].configure(state="disabled")

        # Un label de sortie est ajouté pour afficher le cout de l'armée courante, il devient rouge si une limite
        # est en vigueur mais aussi si elle est dépasséé
        self.sortie = Label(self, textvariable=self.fen.labelSortie, pady=10, relief='groove')
        self.sortie.grid(column=1, columnspan=2, pady=5, sticky='EW')
        self.fen.labelSortie.set(u"Coût de l'armée")

        # Un label pour l'affichage des statistiques de l'armée en cours de formation, affiche les totaux généraux
        self.stats = Label(self, textvariable=self.fen.statsVar, pady=10)
        self.stats.grid(column=1, columnspan=2, pady=5, sticky='EW')
        self.fen.statsVar.set(u"Statistiques")

        if 'alea' in kwargs:
            self.aleatoire = Button(self, text="Créer une armée aléatoire", command=self.armee_aleatoire)
            self.aleatoire.grid(column=1, columnspan=2, pady=5, sticky="EW")

        if 'recup' in kwargs:
            self.labelFrame = LabelFrame(self, text="Récupérer l'armée courante de", pady=5, padx=5)
            Radiobutton(self.labelFrame, text="Armée Solo", variable=self.recupArmee, value=0,
                        command=self.recup_troupes_armee).grid(column=0, row=0)
            Radiobutton(self.labelFrame, text="Armée Multi j1", variable=self.recupArmee, value=1,
                        command=self.recup_troupes_armee).grid(column=1, row=0)
            Radiobutton(self.labelFrame, text="Armée Multi j2", variable=self.recupArmee, value=2,
                        command=self.recup_troupes_armee).grid(column=2, row=0)
            Radiobutton(self.labelFrame, text="Armée Optimisateur", variable=self.recupArmee, value=3,
                        command=self.recup_troupes_armee).grid(column=3, row=0)
            self.labelFrame.grid(padx=10, pady=10, columnspan=2, column=1)

        self.validate = Button(self, text="Valider mon armée", width=20, command=self.fen.validate)
        self.validate.grid(column=1, columnspan=2,
                           pady=5)
        self.boutquit = Button(self, text='Quitter', width=20, command=self.fen.quitter_top_level, bg=colorquit)
        self.boutquit.grid(column=1, columnspan=2)

    def recup_troupes_armee(self):
        """Méthode permettant de récupérer les troupes d'une armée courante, selon le choix de l'utilisateur, elle
        sera ajoutée aux scales de la frame."""
        if askyesno("Récupérer ?", "Voulez-vous récupérer cette armée"):
            if self.recupArmee.get() == 0:
                self.armeeRecup = MaFen.armeeSolo
            elif self.recupArmee.get() == 1:
                self.armeeRecup = MaFen.armeej1
            elif self.recupArmee.get() == 2:
                self.armeeRecup = MaFen.armeej2
            elif self.recupArmee.get() == 3:
                self.armeeRecup = MaFen.armeeOpti
            else:
                print("Error récupération armée / Sélection Troupes")
            for scale in self.fen.scales:
                self.fen.scales[scale].var.set(len(self.armeeRecup.troupes[scale]))
                MaFen.troupes[scale] = len(self.armeeRecup.troupes[scale])
            self.update()

    def armee_aleatoire(self):
        """Méthode pour la génération d'une armée aléatoire, fait un grid_forget de tous les éléments et ajoute un entry
        et un bouton valider. Fait appel à validate_armee pour générer l'armée.
        Une fois l'armée générée, les scales prennent les valeurs ce cette armée générée."""
        for scale in self.fen.scales:
            self.fen.scales[scale].grid_remove()
        self.sortie.grid_remove()
        self.stats.grid_remove()
        self.aleatoire.grid_remove()
        self.validate.grid_remove()
        self.fen.bind("<Return>", self.validate_armee)
        self.boutquit.grid_remove()

        self.reponse_points.set("Combien de points voulez-vous ?")

        self.entree_points.grid(pady=10, padx=10)

        self.button_validate_aleatoire = Button(self, text="Générer aléatoirement une armée",
                                                command=self.validate_armee)
        self.button_validate_aleatoire.grid()

        self.quitter_aleatoire = Button(self, text="Retour", command=self.reinitialize, bg=colorquit)
        self.quitter_aleatoire.grid()

        self.entree_points.focus_set()
        self.entree_points.selection_range(0, END)

    def validate_armee(self, *args):
        """Méthode qui se déclenche lors de l'appui sur le bouton de validation de l'armée aléatoire sélectionnée par
        l'utilisateur. Cette méthode génère l'armée aléatoire et la place dans self.armee. Vérification de l'entrée du
        nombre de points"""
        MaFen.unused(args)
        if str.isnumeric(self.reponse_points.get()):
            self.armee = A.Armee()
            self.armee.former_armee_aleatoire(int(self.reponse_points.get()))
            self.reinitialize()
            str_stats = "PV : " + str(self.armee.PV) + "    PA : " + str(self.armee.PA) + "    DF : " + \
                        str(self.armee.DF) + "    VIT : " + str(self.armee.VIT)
            self.fen.statsVar.set(str_stats)
            self.fen.labelSortie.set(str(self.armee.COUT) + " points")
        else:
            showerror("Erreur", "Vous n'avez pas saisi un nombre de points correct")

    def reinitialize(self):
        """Cette méthode remet les scales et enlève les boutons pour la génération d'armées aléatoire; remet également
        l'évènement de base de la touche Entrée."""
        self.entree_points.grid_forget()
        self.button_validate_aleatoire.grid_forget()
        self.quitter_aleatoire.grid_forget()

        self.fen.bind("<Return>", self.fen.validate)
        for scale in self.fen.scales:
            self.fen.scales[scale].grid()
            self.fen.scales[scale].var.set(len(self.armee.troupes[scale]))
            MaFen.troupes[scale] = len(self.armee.troupes[scale])
        self.sortie.grid()
        self.stats.grid()
        self.aleatoire.grid()
        self.validate.grid()
        self.boutquit.grid()


class EnregistrerArmee(Toplevel):
    """Classe héritant de Toplevel pour l'enregistrement d'une armée. Elle permet de créer des curseurs pour ensuite
    choisir l'effectif de son armée et l'enregistrer avec un nom dans un fichier json."""

    def __init__(self, fen):
        """Constructeur de la classe EnregistrerArmee, nous instancions une Toplevel par rapport à la fenêtre principale
        La frame SelectionTroupes est ajoutée avec comme option la récupération d'une armée courante.
        Un champ d'entrée utilisateur permet de donner un nom à l'armée pour ensuite l'enregistrer.
        Le champ LabelSortie est modifié lorsque nous changeons la valeur d'un curseur, il donne le cout total de
        l'armée.
        """
        Toplevel.__init__(self, fen)
        self.grid()
        self.title("Enregistrement d'une armée")
        self.fen = fen
        self.scales = {}
        self.fen.reinitialiser_troupes()

        self.labelSortie = StringVar()
        self.statsVar = StringVar()
        self.entreeUtilisateur = StringVar()

        self.entree = Entry(self, textvariable=self.entreeUtilisateur)
        self.entree.grid(pady=10, sticky='EW', padx=50)
        self.entreeUtilisateur.set(u"Nom Armée, Entrée pour valider")
        self.entree.bind("<Return>", self.validate)
        self.entree.focus_set()
        self.entree.selection_range(0, END)

        # Ajout de la frame pour la sélection des troupes
        self.selection = SelectionTroupes(self, A.Armee(), recup=True)
        self.selection.grid()

    def validate(self, *args):
        """La méthode validate_armee permet de sérialiser dans un fichier json l'ensemble du dictionnaire MaFen.troupes.
        Le fichier porte le nom de l'entrée de l'utilisateur, et par defaut : 'default.json'
        Ouverture d'un fichier portant le nom de l'armée + .json possible : encodage du dictionnaire MaFen.troupes avec
        indentation 4."""
        MaFen.unused(args)
        if self.entreeUtilisateur.get() == "Nom Armée, Entrée pour valider" or self.entreeUtilisateur.get() == "":
            self.entreeUtilisateur.set("default")
        with open(self.entreeUtilisateur.get() + '.json', 'w', encoding='utf-8') as f:
            json.dump(MaFen.troupes, f, indent=4)

        self.quitter_top_level()

    def quitter_top_level(self, *args):
        """Permet de quitter la Toplevel sans quitter la fenêtre principale, pour quitter la fenetre principale en plus
        ajouter self.quit()"""
        MaFen.unused(args)
        self.destroy()


class NouvelleArmee(Toplevel):
    """Classe permettant la conception d'une nouvelle armée pour un utilisateur qui n'est pas à enregistrer.
     Elle sert pour la conception des armées solo et multijoueur et prend en paramètre 'armee' qui correspond à l'armée
     pour laquelle il ne faut pas dépasser le nombre de points.
     La nouvelle armée est enregistrée dans la variable correpondante à l'armée de la fenêtre principale."""

    def __init__(self, fen, armee):
        """Initialisation de la classe, la liste des carac est réinitialisée pour permettre la création d'une
        nouvelle armée"""
        Toplevel.__init__(self, fen)
        self.grid()
        self.title("Enregistrement d'une armée")
        self.fen = fen
        self.armee = armee
        self.scales = {}

        self.fen.reinitialiser_troupes()

        self.labelSortie = StringVar()
        self.statsVar = StringVar()

        # Ajout de la frame pour la sélection des troupes avec pour option la génération d'une armée aléatoire.
        # Nous passons aussi le nombre de points maximum
        self.selection = SelectionTroupes(self, armee, alea=True)
        self.selection.grid()

    def validate(self, *args):
        """Enregistrement de la nouvelle armée créée dans l'armée correspondante. Une armée est générée pour pouvoir
        directement l'utiliser pour des combats par la suite."""
        MaFen.unused(args)
        a = A.Armee()
        a.former_armee_simple(MaFen.troupes)

        # Nous testons pour savoir quelle armée il faut modifier, nous utilisons un test sur les références des objets
        # Le test porte sur l'armée pour laquelle il ne faut pas dépasser le nombre de points. C'est donc l'armée
        # adverse que l'on modifie
        if self.armee == MaFen.armeeOpti:
            # Nous sommes en train de choisir l'armée du joueur solo
            if self.armee.COUT != 0 and a.COUT > self.armee.COUT:
                showwarning("Erreur", "Impossible de valider l'armée\nTrop de points, maximum " + str(
                    self.armee.COUT) + " points")
            else:
                MaFen.armeeSolo = copy.deepcopy(a)
                self.quitter_top_level()

        elif self.armee == MaFen.armeej2:
            # Nous sommes en train de choisir l'armée du joueur 1 en multijoueur
            if self.armee.COUT != 0 and a.COUT > MaFen.armeej2.COUT:
                showwarning("Erreur", "Impossible de valider l'armée\nTrop de points, maximum " + str(
                    self.armee.COUT) + " points")
            else:
                MaFen.armeej1 = copy.deepcopy(a)
                self.quitter_top_level()

        elif self.armee == MaFen.armeej1:
            # Nous sommes en train de choisir l'armée du joueur 2 en multijoueur
            if self.armee.COUT != 0 and a.COUT > self.armee.COUT:
                showwarning("Erreur", "Impossible de valider l'armée\nTrop de points, maximum " + str(
                    self.armee.COUT) + " points")
            else:
                MaFen.armeej2 = copy.deepcopy(a)
                self.quitter_top_level()
        else:
            print("Error validate_armee NouvelleArmee")

    def quitter_top_level(self, *args):
        """Quitte la Toplevel sans fermer le programme principal"""
        MaFen.unused(args)
        self.destroy()


class RecupererArmee(Frame):
    """Classe de récupération d'une armée, c'est une Toplevel par rapport à la fenêtre principale
    Permet de récupérer une armée enregistrée dans un fichier soit avec son nom ou alors directement par un explorateur
    de fichier."""

    def __init__(self, fen):
        """Initialisation de la classe RecupererArmee
        Un champ d'entrée utilisateur est ajouté pour saisir un nom d'armée enregistré, et un bouton choisir un fichier
        json qui permet d'ouvrir un explorateur et de sélectionner une armée enregistrée.
        Le focus est par défaut initialisé sur le champ de texte."""
        Frame.__init__(self, fen)
        self.nomFrame = "Récupération d'une armée"
        self.fen = fen
        self.bind("<Escape>", self.fen.quitter)

        self.entreeUtilisateur = StringVar()
        self.entreeUtilisateur.set(u"Nom de l'armée à chercher")
        self.enregistrement = IntVar()

        self.entree = Entry(self, textvariable=self.entreeUtilisateur)
        self.entree.pack(pady=5, padx=20)
        self.entree.bind("<Return>", self.validation_entry)
        self.entree.focus_set()
        self.entree.selection_range(0, END)
        self.armeeTemp = A.Armee()

        Button(self, text="Choisir fichier json", width=20, command=self.askuser, bg='white smoke').pack(pady=5)
        l1 = LabelFrame(self, text="Où voulez-vous stocker l'armée ?", pady=5, padx=5)
        Radiobutton(l1, text="Armée Solo", variable=self.enregistrement, value=0).pack()
        Radiobutton(l1, text="Armée Multijoueur 1", variable=self.enregistrement, value=1).pack()
        Radiobutton(l1, text="Armée Multijoueur 2", variable=self.enregistrement, value=2).pack()
        l1.pack(padx=10, pady=10)

        Button(self, text='Valider', width=20, command=self.validation_entry).pack()
        Button(self, text="Retour à l'accueil", width=20, bg=colorquit,
               command=lambda x="Accueil": self.fen.changer_frame(x)).pack()

    def validation_entry(self, *args):
        """Met en forme l'entrée de l'utilisateur en chemin direct dans le dossier courant d'éxécution"""
        self.entreeUtilisateur.set("./" + self.entreeUtilisateur.get() + '.json')
        self.on_press_enter()
        MaFen.unused(args)

    def askuser(self):
        """Interface de choix de fichier pour sélectionner une armée déjà enregistrée. Un explorateur de fichiers
        s'ouvre et permet la sélection des fichiers uniquement de type json.
        Le chemin absolu est placé dans l'entrée utilisateur qui servira à ouvrir le fichier.
        Nous testons si l'utilisateur sélectionne bien un fichier."""
        value = askopenfilename(filetypes=[("JSON", "*.json")], defaultextension='.json', parent=self)
        if not isinstance(value, tuple) and value != '':
            self.entreeUtilisateur.set(value)
            self.on_press_enter()

    def on_press_enter(self):
        """Méthode se déclanchant après modification du chemin vers le fichier.
        Permet de valider la saisie du texte dans le champ d'entrée.
        Test pour vérifier que le fichier existe.
        Si il existe, alors nous modifions l'armée choisie par l'utilisateur. sinon nous affichons une pop-up indiquant 
        que l'armée n'existe pas.
        Pour enregistrer la nouvelle armée, le fichier json est récupéré et converti en dictionnaire, le dictionnaire
        MaFen.troupes prend cette valeur et une armée est formée."""
        name = self.entreeUtilisateur.get()

        if os.path.isfile(name):
            # Test pour vérifier que le fichier existe, sinon alerte visuelle
            with open(name) as json_data:
                troupes = json.load(json_data)

            a = A.Armee()
            a.former_armee_simple(troupes)  # Alors nous formons l'armée correspondante à ce fichier
            self.entreeUtilisateur.set("Nom de l'armée à chercher")
            self.entree.focus_set()
            self.entree.selection_range(0, END)
            self.update()
            tt = "Armée " + os.path.basename(name)

            if self.enregistrement.get() == 0:
                self.armeeTemp = copy.deepcopy(MaFen.armeeSolo)
                MaFen.armeeSolo = copy.deepcopy(a)
                AfficherArmee(self, MaFen.armeeSolo, text=tt, recup=0)
            elif self.enregistrement.get() == 1:
                self.armeeTemp = copy.deepcopy(MaFen.armeej1)
                MaFen.armeej1 = copy.deepcopy(a)
                AfficherArmee(self, MaFen.armeej1, text=tt, recup=1)
            elif self.enregistrement.get() == 2:
                self.armeeTemp = copy.deepcopy(MaFen.armeej2)
                MaFen.armeej2 = copy.deepcopy(a)
                AfficherArmee(self, MaFen.armeej2, text=tt, recup=2)
            else:
                print("Error, récup armée enregistrement")

        else:
            showwarning("Entrée invalide", "Votre armée n'existe pas")
            print("Le fichier", self.entreeUtilisateur.get(), "n'existe pas")
            self.entreeUtilisateur.set("Nom de l'armée à chercher")
            self.entree.focus_set()
            self.entree.selection_range(0, END)


class AfficherStats(Toplevel):
    """Classe pour l'affichege des caractéristiques des carac dans une toplevel"""

    def __init__(self, fen):
        """Top level pour afficher l'ensemble des caractéristiques des troupes dans le fichier Troupes
        Des labels sont créés et ajoutés à la grille en colonnes"""
        Toplevel.__init__(self, fen)
        self.title("Affichage des caractéristiques")
        self.frame = Frame(self)
        self.frame.grid()
        self.fen = fen
        self.bind("<Escape>", self.quitter_top_level)
        self.troupes_carac = Tr.Troupe.carac.values()
        Label(self.frame, text="  NOM  ", bd=5, bg="#fefee2", anchor='e').grid(column=0, row=0)
        Label(self.frame, text="VITESSE", bd=5, bg="#fefee2").grid(column=1, row=0)
        Label(self.frame, text="ATTAQUE", bd=5, bg="#fefee2").grid(column=2, row=0)
        Label(self.frame, text="DEFENSE", bd=5, bg="#fefee2").grid(column=3, row=0)
        Label(self.frame, text="VITTESSE", bd=5, bg="#fefee2").grid(column=4, row=0)
        Label(self.frame, text=" COUT ", bd=5, bg="#fefee2").grid(column=5, row=0)
        Label(self.frame, text="HIERARCHIE", bd=5, bg="#fefee2").grid(column=6, row=0)
        for i, carac in enumerate(self.troupes_carac):
            Label(self.frame, text=carac[0], justify='right').grid(column=0, row=i + 1, padx=5)
            Label(self.frame, text=carac[1]).grid(column=1, row=i + 1, padx=5)
            Label(self.frame, text=carac[2]).grid(column=2, row=i + 1, padx=5)
            Label(self.frame, text=carac[3]).grid(column=3, row=i + 1, padx=5)
            Label(self.frame, text=carac[4]).grid(column=4, row=i + 1, padx=5)
            Label(self.frame, text=carac[5]).grid(column=5, row=i + 1, padx=5)
            Label(self.frame, text=carac[6]).grid(column=6, row=i + 1, padx=5)

        l1 = LabelFrame(self.frame, text="Limites", pady=5, padx=5)
        Label(l1, text="Une catapulte pour 250 points", anchor="w").grid()
        Label(l1, text="Un chariot pour 150 points", anchor="w").grid()
        Label(l1, text="Un éléphant de combat pour 200 points", anchor="w").grid()
        Label(l1, text="Maximum 3 généraux", anchor="w").grid()
        l1.grid(padx=10, pady=10, columnspan=7)

        self.frame.pack()
        Button(self, text="Quitter l'affichage", width=30, command=self.quitter_top_level, bg=colorquit).pack(pady=5)

    def quitter_top_level(self, *args):
        """Permet de simplement quitter la Toplevel sans fermer la fenetre principale"""
        MaFen.unused(args)
        self.destroy()


class AfficherArmee(Toplevel):
    """Classe héritant de l'objet Toplevel, permet la représentation d'une armée
    Cette méthode à besoin que les armées soit instanciées, elle récupère la liste des
    troupes et les enumère pour créer un LabelAffichage avec en paramètre le nom et le nombre d'unités correspondant
    L'armée est passée directement en paramètre du init.
    Un champ sur deux possède une couleur de fond différente pour faciliter la lecture.
    La toplvel prend le nom de l'armée passé en paramèter dans 'text'. L'option 'recup' permet d'ajouter un bouton de
    validation de choix, utilisé pour la récupération d'une armée. Renvoi vers les méthodes de la classe supérieure"""

    def __init__(self, fen, armee, **kwargs):
        """Une armée est passée en paramètre et la Toplevel s'occupe de l'afficher correctement"""
        Toplevel.__init__(self, fen)
        self.grid()
        self.fen = fen
        self.armee = armee
        self.bind("<Escape>", self.quitter_top_level)
        self.bind("<Return>", self.quitter_top_level)
        if 'text' in kwargs:
            self.title(kwargs['text'])
        else:
            self.title("Affichage de l'armée")

        self.liste_troupes = self.armee.troupes

        j = 0
        for troupe in self.liste_troupes:
            if len(self.liste_troupes[troupe]) > 0:
                if self.liste_troupes[troupe][0].nom != "Généraux":
                    string = str(len(self.liste_troupes[troupe])) + " " + self.liste_troupes[troupe][0].nom + "s"
                else:
                    string = str(len(self.liste_troupes[troupe])) + " " + self.liste_troupes[troupe][0].nom
                if j % 2 == 0:
                    LabelAffichage(self, text=string, bg="#f7937f").grid()
                else:
                    LabelAffichage(self, text=string, bg="#e6b8af").grid()
                j = j + 1

        if 'recup' in kwargs:
            self.recup = kwargs['recup']
            Button(self, text="Valider mon choix", width=20, command=self.quitter_top_level).grid(pady=5)
            Button(self, text='Quitter sans enregistrer', width=20, command=self.quit_without).grid(pady=5)
            FrameStatsArmee(self, self.armee).grid()
        else:
            FrameStatsArmee(self, self.armee).grid()
            Button(self, text="Quitter l'affichage", width=30, command=self.quitter_top_level, bg=colorquit).grid()

    def quitter_top_level(self, *args):
        """Permet de quitter la Toplevel sans quitter la fenêtre principale. Cette méthode garde la nouvelle armée."""
        MaFen.unused(args)
        self.destroy()

    def quit_without(self):
        """Cette méthode quitte l'affichage mais remet l'armée enregistrée dans armeeTemp dans l'armée modifiée
        pour quitter sans enregistrer."""
        if self.recup == 0:
            MaFen.armeeSolo = copy.deepcopy(self.fen.armeeTemp)
        elif self.recup == 1:
            MaFen.armeej1 = copy.deepcopy(self.fen.armeeTemp)
        elif self.recup == 2:
            MaFen.armeej2 = copy.deepcopy(self.fen.armeeTemp)
        self.destroy()


class FrameStatsArmee(Frame):
    """Frame contenant les informations sur une armée pour son affichage dans 6 labels, utilisé dans AfficherArmee."""

    def __init__(self, fen, armee, *args, **kwargs):
        Frame.__init__(self, fen, *args, **kwargs)
        self.armee = armee
        self.grid()
        points = "Coût : " + str(armee.COUT)
        pv = "PV : " + str(armee.PV)
        pa = "PA : " + str(armee.PA)
        df = "DF : " + str(armee.DF)
        vit = "VIT : " + str(armee.VIT)

        Label(self, text="Statistiques de l'armée :", bg="#ADD8E6").grid(columnspan=5)
        Label(self, text=points, bg="#fefee2").grid(column=0, row=1, pady=5, padx=5)
        Label(self, text=pv, bg="#fefee2").grid(column=1, row=1, pady=5, padx=5)
        Label(self, text=pa, bg="#fefee2").grid(column=2, row=1, pady=5, padx=5)
        Label(self, text=df, bg="#fefee2").grid(column=3, row=1, pady=5, padx=5)
        Label(self, text=vit, bg="#fefee2").grid(column=4, row=1, pady=5, padx=5)


class MenuAccueil(Frame):
    """Frame pour l'affichage de l'accueil."""

    def __init__(self, fen, *args, **kwargs):
        Frame.__init__(self, fen, *args, **kwargs)
        self.fen = fen
        self.nomFrame = "Menu Accueil"
        Button(self, text="Menu Solo", command=lambda x="Solo": self.fen.changer_frame(x), width=30).pack()
        Button(self, text="Menu Multijoueur", command=lambda x="Multijoueur": self.fen.changer_frame(x),
               width=30).pack()
        Button(self, text="Menu Optimisateur", command=lambda x="Optimisateur": self.fen.changer_frame(x),
               width=30).pack()
        Button(self, text="Enregistrer une Armée", command=lambda x=self.fen: EnregistrerArmee(x), width=30).pack()
        Button(self, text="Afficher caractéristiques", command=lambda x=self.fen: AfficherStats(x), width=30).pack()
        Button(self, text="Afficher règles", command=lambda x="Regles": self.fen.changer_frame(x), width=30).pack()
        Button(self, text="FAQ", command=lambda x="FAQ": self.fen.changer_frame(x), width=30).pack()
        Button(self, text="Reset", command=self.fen.reset, width=30).pack()
        Button(self, text="Quitter", command=self.fen.quitter, width=30, bg=colorquit).pack()


class MenuSolo(Frame):
    """Frame pour l'affichage du Menu Solo."""

    def __init__(self, fen, *args, **kwargs):
        Frame.__init__(self, fen, *args, **kwargs)
        self.fen = fen
        self.nomFrame = "Menu Solo"
        Button(self, text="Créer mon armée", command=lambda: NouvelleArmee(self.fen, MaFen.armeeOpti),
               width=30).pack()
        Button(self, text="Afficher mon armée", command=lambda x=0: AfficherArmee(self.fen, MaFen.armeeSolo,
                                                                                  text="Votre Armée"), width=30).pack()
        Button(self, text="Récupérer une Armée", command=lambda x="Recuperer": self.fen.changer_frame(x),
               width=30).pack()
        Button(self, text="Combattre contre IA", command=self.fen.combat_ia, width=30).pack()
        Button(self, text="Combattre contre aléatoire", command=self.fen.combat_alea, width=30).pack()
        Button(self, text="Retour à l'accueil", command=lambda x="Accueil": self.fen.changer_frame(x), width=30,
               bg=colorquit).pack()


class MenuMultijoueur(Frame):
    """Frame pour l'affichage du Menu Multijoueur."""

    def __init__(self, fen, *args, **kwargs):
        Frame.__init__(self, fen, *args, **kwargs)
        self.fen = fen
        self.nomFrame = "Menu Multijoueur"
        Button(self, text="Créer Armée joueur 1", command=lambda: NouvelleArmee(self.fen, MaFen.armeej2),
               width=30).pack()
        Button(self, text="Créer Armée joueur 2", command=lambda: NouvelleArmee(self.fen, MaFen.armeej1),
               width=30).pack()
        Button(self, text="Afficher Armée joueur 1", command=lambda x=1: AfficherArmee(self.fen, MaFen.armeej1,
                                                                                       text="Armée joueur 1"),
               width=30).pack()
        Button(self, text="Afficher Armée joueur 2", command=lambda x=2: AfficherArmee(self.fen, MaFen.armeej2,
                                                                                       text="Armée joueur 2"),
               width=30).pack()
        Button(self, text="Récupérer une Armée", command=lambda x="Recuperer": self.fen.changer_frame(x),
               width=30).pack()
        Button(self, text="Combattre", command=self.fen.combat1v1, width=30).pack()
        Button(self, text="Retour à l'accueil", command=lambda x="Accueil": self.fen.changer_frame(x), width=30,
               bg=colorquit).pack()


class MenuOptimisateur(Frame):
    """Frame pour l'interface de lancement de l'optimisateur"""

    def __init__(self, fen, *args, **kwargs):
        Frame.__init__(self, fen, *args, **kwargs)
        self.fen = fen
        self.nomFrame = "Menu Optimisateur"
        self.optimisateurPoints = StringVar()
        self.optimisateurIA = IntVar()
        self.optimisateurNiveau = IntVar()
        self.optimisateurCroisement = IntVar()
        self.optimisateurChoix = IntVar()
        self.optimisateurEvaluation = IntVar()
        self.optimisateurPoints.set("Choisissez le nombre de points")
        self.entreeOptimisatateur = Entry(self, textvariable=self.optimisateurPoints, width=30)
        self.entreeOptimisatateur.grid(row="0", column="0", pady="5", padx="5")
        self.entreeOptimisatateur.focus_set()
        self.entreeOptimisatateur.selection_range(0, END)

        self.entreeOptimisatateur.bind("<Return>", self.fen.lancer_optimisateur)
        self.bind("<Escape>", self.fen.quitter)

        l1 = LabelFrame(self, text="IA Faible ou Forte ?", pady=5, padx=5)
        Radiobutton(l1, text="IA Faible", variable=self.optimisateurIA, value=0).grid(row="0", column="0")
        Radiobutton(l1, text="IA Forte", variable=self.optimisateurIA, value=1).grid(row="0", column="1")
        l1.grid(padx=10, pady=10)

        l2 = LabelFrame(self, text="Niveau de l'IA", pady=5, padx=5)
        Radiobutton(l2, text="Niveau 1", variable=self.optimisateurNiveau, value=0).grid()
        Radiobutton(l2, text="Niveau 2", variable=self.optimisateurNiveau, value=1).grid()
        Radiobutton(l2, text="Niveau 3", variable=self.optimisateurNiveau, value=2).grid()
        Radiobutton(l2, text="Niveau 4", variable=self.optimisateurNiveau, value=3).grid()
        l2.grid(padx=10, pady=10)

        l3 = LabelFrame(self, text="Avec croisements ?", pady=5, padx=5)
        Radiobutton(l3, text="Non", variable=self.optimisateurCroisement, value=0).grid()
        Radiobutton(l3, text="Oui", variable=self.optimisateurCroisement, value=1).grid()
        l3.grid(padx=10, pady=10)

        l4 = LabelFrame(self, text="Activer l'algorithme d'évaluation ?", pady=5, padx=5)
        Radiobutton(l4, text="Non", variable=self.optimisateurEvaluation, value=0).grid()
        Radiobutton(l4, text="Oui", variable=self.optimisateurEvaluation, value=1).grid()
        l4.grid(padx=10, pady=10)

        l5 = LabelFrame(self, text="Enregistrement", pady=5, padx=5)
        Radiobutton(l5, text="Enregistrer dans mon armée", variable=self.optimisateurChoix, value=0).grid()
        Radiobutton(l5, text="Préparer l'armée pour l'IA", variable=self.optimisateurChoix, value=1).grid()
        Radiobutton(l5, text="Enregistrer dans un fichier json", variable=self.optimisateurChoix, value=2).grid()
        l5.grid(padx=10, pady=10)

        Button(self, text="Valider", command=self.fen.lancer_optimisateur, width=30).grid()
        Button(self, text="Retour à l'accueil", command=lambda x="Accueil": self.fen.changer_frame(x), width=30,
               bg=colorquit).grid(
            pady=3)


class FrameResultat(Frame):
    """Frame correspondant à une victoire du joueur solo contre IA ou aléatoire.
    Nous passons un texte à afficher et la photo correspondante"""

    def __init__(self, fen, photo, *args, **kwargs):
        Frame.__init__(self, fen, *args, **kwargs)
        self.fen = fen
        self.nomFrame = "Résultat du combat"
        im = PILIMAGE.open('Images/' + photo)
        x, y = im.size
        self.photo = PhotoImage(file="Images/" + photo)
        self.canvas = Canvas(self, width=x, height=y)
        self.canvas.create_image(0, 0, anchor=NW, image=self.photo)
        self.canvas.pack()

        Button(self, text="Retour à l'accueil", command=lambda: self.fen.changer_frame("Accueil"),
               width=30, bg=colorquit).pack(fill=BOTH)


class Regles(Frame):
    """Frame pour afficher les règles du jeu dans la fenêtre principale. Les Règles sont stockées dans un fichier txt.
    Test pour vérifier que le fichier existe, si oui son contenu est ajouté au label"""

    def __init__(self, fen, *args, **kwargs):
        Frame.__init__(self, fen, *args, **kwargs)
        self.fen = fen
        self.nomFrame = "Affichage des règles"
        Label(self, text="Règles", bg="#DAB48D").pack(fill=BOTH)
        if os.path.isfile("./Regles.txt"):
            regles = open("Regles.txt", "r", encoding="utf-8")
            afficherregles = regles.read()
            Label(self, text=afficherregles, padx=3, pady=3, justify='center', width=100).pack()
        else:
            Label(self, text="File not found", bg="red").pack(fill=BOTH)

        Button(self, text="Retour à l'accueil", command=lambda: self.fen.changer_frame("Accueil"), width=30,
               bg=colorquit).pack()


class Faq(Frame):
    """Frame pour afficher la FAQ du jeu dans la fenêtre principale. La FAQ est stockée dans un fichier txt.
    Test pour vérifier que le fichier existe, si oui son contenu est ajouté au label"""

    def __init__(self, fen, *args, **kwargs):
        Frame.__init__(self, fen, *args, **kwargs)
        self.fen = fen
        self.nomFrame = "Affichage FAQ"
        Label(self, text="FAQ", bg="#DAB48D").pack(fill=BOTH)
        if os.path.isfile("./FAQ.txt"):
            faq = open("FAQ.txt", "r", encoding="utf-8")
            afficherfaq = faq.read()
            Label(self, text=afficherfaq, padx=3, pady=3, justify="center", width=100).pack()
        else:
            Label(self, text="File not found", bg="red").pack(fill=BOTH)
        Button(self, text="Retour à l'accueil", command=lambda: self.fen.changer_frame("Accueil"), width=30,
               bg=colorquit).pack()


class MaFen(Tk):
    """Classe principale et fenetre principale, elle permet de lancer l'ensemble des Toplevel et de stocker les
    informations qui servent entre elles. Les armées des joueurs sont stockées dans des attributs d'instance (ils
    pourraient aussi devenir des attributs de classe pour accès plus simple).
    Un dictionnaire frames comporte l'ensemble des frames initialisées avec leurs paramètres pour la navigation.
    Des armées de base sont stockées dans la classe. La frame accueil est ajoutée par défaut.
    Chaque bouton lance sa Toplevel"""
    troupes = {}
    armeeSolo = A.Armee()
    armeej1 = A.Armee()
    armeej2 = A.Armee()
    armeeOpti = A.Armee()

    def __init__(self):
        Tk.__init__(self)
        self.title("Wargame MGL")
        self.bind("<Escape>", self.quitter)
        self.frames = {
            "Accueil": MenuAccueil(self),
            "Solo": MenuSolo(self),
            "Multijoueur": MenuMultijoueur(self),
            "Recuperer": RecupererArmee(self),
            "Optimisateur": MenuOptimisateur(self),
            "WinningFrame": FrameResultat(self, "victoire.gif"),
            "LosingFrame": FrameResultat(self, "defaite.gif"),
            "Victory1": FrameResultat(self, "victoire_joueur1.gif"),
            "Victory2": FrameResultat(self, "victoire_joueur2.gif"),
            "Egalite": FrameResultat(self, "egalite.gif"),
            "Regles": Regles(self),
            "FAQ": Faq(self),
            "Combat1": FrameResultat(self, 'combat_en_cours1.gif'),
            "Combat2": FrameResultat(self, 'combat_en_cours2.gif')
        }
        # Nous ajoutons par défaut la frame de l'accueil et nous la placons dans currentFrame
        self.frames["Accueil"].pack()
        self.currentFrame = self.frames["Accueil"]
        self.top = Frame(self)

    def afficher_combat(self):
        """Affiche simultanement les photos avec des frames pack et pack_forget pour simuler la durée d'un combat."""

        for i in range(0, 3):
            self.changer_frame('Combat1')
            self.update()
            time.sleep(0.8)
            self.changer_frame('Combat2')
            self.update()
            time.sleep(0.8)

    def changer_frame(self, nom):
        """Méthode permettant de changer de Frame de la fenêtre principale. Cette méthode va pack_forget la frame
        actuelle pour la remplacer par celle correspondant au nom donné en paramètre. Le titre de la fenêtre devient
        celui de l'attribut title de la currentFrame."""
        self.currentFrame.pack_forget()
        self.currentFrame = self.frames[nom]
        self.currentFrame.pack()
        self.title(self.currentFrame.nomFrame)

    def combat_ia(self):
        """Méthode permettant de lancer un combat contre l'Optimisateur. Vérification si les armées sont présentes sinon
        une pop-up apparaît pour signaler quelle armée est manquante. L'utilisateur doit générer l'armée depuis
        l'optimisateur en choississant l'option fermer pour l'IA.
        Le combat est ensuite lancé avec le module moteurCombat. Le résultat fait apparapitre la frame correspondante
        Note : Il faut passer des copies au moteur de combat pour ne pas supprimer les troupes de l'armée directement.
        Le module copy avec la fonction deepcopy permet de copier en profondeur l'objet et pas seulement ses méthodes.
        """
        if MaFen.armeeOpti.COUT != 0:
            if MaFen.armeeSolo.COUT != 0:
                armee_gagnante = Mc.moteur_de_combat(copy.deepcopy(MaFen.armeeSolo), copy.deepcopy(MaFen.armeeOpti))
                self.afficher_combat()
                if armee_gagnante == 1:
                    print('Armée utilisateur à gagnée')
                    self.changer_frame("WinningFrame")
                elif armee_gagnante == 2:
                    print('Armée IA à gagnée')
                    self.changer_frame("LosingFrame")
                else:
                    print("Aucun gagnant, égalité")
                    self.changer_frame('Egalite')
                print('<----------------->Armée utilisateur </----------------->')
                MaFen.armeeSolo.afficher_armee_simple()
                print('<----------------->Armée IA </----------------->')
                MaFen.armeeOpti.afficher_armee_simple()
            else:
                showwarning("Erreur", "Formez votre armée avant")
        else:
            showwarning("Erreur", "Formez d'abord une armée depuis l'optimisateur")
            self.changer_frame("Optimisateur")

    def combat_alea(self):
        """Méthode pour faire combattre l'armée contenu dans MaFen.armeeSolo contre une armée générée troupe par troupe.
        L'armée aléatoire possède le même nombre de points que celle de l'utilisateur.
        Si l'armée utilisateur n'est pas encore prête un message apparait.
        Des copies sont passées au moteur de combat pour éviter de modifier directement les armées.
        La frame correspondant à la victoire ou la défaite est ensuite affichée et les armées sont affichées
        dans le terminal sous forme simple"""
        if MaFen.armeeSolo.COUT == 0:
            showwarning("Pas d'armée utilisateur", "Vous ne possédez pas encore d'armée")
        else:
            armee_ordi = A.Armee()
            armee_ordi.former_armee_aleatoire(MaFen.armeeSolo.COUT)
            armee_gagnante = Mc.moteur_de_combat(copy.deepcopy(MaFen.armeeSolo), copy.deepcopy(armee_ordi))
            self.afficher_combat()
            # On met des copies des armées à combattre entres elles pour ensuite pouvoir les garder en mémoire
            if armee_gagnante == 1:
                print('Armée utilisateur à gagnée')
                self.changer_frame('WinningFrame')
            elif armee_gagnante == 2:
                print('Armée Ordi à gagnée')
                self.changer_frame('LosingFrame')
            else:
                print("Aucun gagnant, égalité")
                self.changer_frame('Egalite')
            print('<----------------->Armée utilisateur </----------------->')
            MaFen.armeeSolo.afficher_armee_simple()
            print('<----------------->Armée aléatoire </----------------->')
            armee_ordi.afficher_armee_simple()

    def combat1v1(self):
        """Même principe que pour le combat Alea, les deux armées contenues dans MaFen.armeej1 et MaFen.armeej2
        s'affrontent, une page de résultat donne le vainqueur. Test au début pour voir si le combat est possible
        Affichage des armées en fin de combat.
        Possibilité de faire match nul."""
        if MaFen.armeej1.COUT == 0:
            showwarning("Pas d'armée joueur 1 ", "Le joueur 1 ne possède pas encore d'armée ! Formez !")
        elif MaFen.armeej2.COUT == 0:
            showwarning("Pas d'armée joueur 2", "Le joueur 2 ne possède pas encore d'armée ! Formez !")
        else:
            armee_gagnante = Mc.moteur_de_combat(copy.deepcopy(MaFen.armeej1), copy.deepcopy(MaFen.armeej2))
            self.afficher_combat()
            if armee_gagnante == 1:
                print('\nArmée joueur 1 à gagnée')
                self.changer_frame('Victory1')
            elif armee_gagnante == 2:
                print('\nArmée joueur 2 à gagnée')
                self.changer_frame('Victory2')
            else:
                print("Aucun gagnant, égalité")
                self.changer_frame('Egalite')
            print('<----------------->Armée joueur 1 </----------------->')
            MaFen.armeej1.afficher_armee_simple()
            print('<----------------->Armée joueur 2 </----------------->')
            MaFen.armeej2.afficher_armee_simple()

    def lancer_optimisateur(self, *args):
        """Cette méthode lance l'optimisateur avec les paramètres donnés par l'utilisateur avec les boutons radio de la
        frame MenuOptimisateur et de la barre de chargement.
        Des alertes permettent la mise en garde contre une augmentation de points avec les croisements.
        Les deux méthodes sont lancées en parralèlle avec le module Thread."""
        MaFen.unused(args)
        if str.isnumeric(self.frames["Optimisateur"].optimisateurPoints.get()):
            if self.frames["Optimisateur"].optimisateurCroisement.get() == 1:
                showinfo("Attention", "Le nombre de points avec les croisements peut être augmenté")
            if MaFen.armeeSolo.COUT != 0 and \
                    int(self.frames["Optimisateur"].optimisateurPoints.get()) > MaFen.armeeSolo.COUT:
                showerror("Erreur", "Impossible de valider cet enregistrement\nL'armée solo possède moins de points")
            else:
                Thread(target=self.progress_bar).start()
                Thread(target=self.algo).start()

    def progress_bar(self):
        """Barre de progression du type indéfini avec le module Tkinter ttk."""
        self.top = Frame(self)
        frame = ttk.Frame(self.top)
        frame.pack(expand=True, fill=BOTH, side=TOP)
        progress = ttk.Progressbar(frame, orient='horizontal', mode='indeterminate', length=300)
        progress.pack(expand=True, fill=BOTH, side=TOP, pady=8)
        progress.start(50)
        self.top.pack()

    def algo(self):
        """Méthode permettant de lancer l'optimisateur avec les paramètres choisis par l'utilisateur. Puis de détruire
        la barre de progression quand l'optimisation est terminée. "time.sleep" permet de donner un temps suffisant
        pour créer la barre et la supprimer si l'optimisateur est trop rapide (peu de points demandés). Il est possible
        d'enregistrer directement les armées produites dans un fichier json qui portera pour nom la date et l'heure"""
        if str.isnumeric(self.frames["Optimisateur"].optimisateurPoints.get()):
            print("\nL'algorithme recherche la meilleure armée possible...\n")
            a = O.algorithme_genetique_parametre(int(self.frames["Optimisateur"].optimisateurPoints.get()),
                                                 self.frames["Optimisateur"].optimisateurIA.get(),
                                                 self.frames["Optimisateur"].optimisateurNiveau.get(),
                                                 self.frames["Optimisateur"].optimisateurCroisement.get(),
                                                 self.frames["Optimisateur"].optimisateurEvaluation.get())
            time.sleep(2)
            # Nous ajoutons un délai de 2 secondes minimum le temps de créer la barre de progression si l'optimisateur
            # va trop vite. Puis nous détruisons la toplevel contenant la progress_bar
            if not a[1]:
                showinfo("Attention", "L'armée n'a pas passé l'évaluation. Vous devriez utiliser la fonction reset du "
                                      "jeu et recommencer pour obtenir une armée plus performante !")
            self.top.pack_forget()
            self.top.destroy()
            if self.frames["Optimisateur"].optimisateurChoix.get() == 0:
                # C'est à dire que l'armée doit être enregistrée dans l'armée courante solo
                MaFen.armeeSolo = copy.deepcopy(a[0])
                AfficherArmee(self, MaFen.armeeSolo, text="Votre armée")
                self.changer_frame("Accueil")
            elif self.frames["Optimisateur"].optimisateurChoix.get() == 1:
                #  Si vaut 1 elle est enregistrée pour être combattue dans le menu solo contre IA
                MaFen.armeeOpti = copy.deepcopy(a[0])
            elif self.frames["Optimisateur"].optimisateurChoix.get() == 2:
                # Si nous souhaitons l'enregistrer dans un fichier json
                date = datetime.datetime.now()
                string = str(date.year) + "." + str(date.month) + "." + str(date.day) + "." + self.frames[
                    "Optimisateur"].optimisateurPoints.get()
                list_troupes = {}
                for troupe in a[0].troupes:
                    list_troupes[troupe] = len(a[0].troupes[troupe])
                with open(string + '.json', 'w', encoding='utf-8') as f:
                    json.dump(list_troupes, f, indent=4)
            else:
                print("Error fonction algo MaFen")

            self.frames["Optimisateur"].optimisateurPoints.set("Nombre de points de votre armée")
            self.changer_frame("Accueil")
        else:
            showwarning("Erreur", "Veuillez rentrer un nombre de points correct")

    def quitter(self, *args):
        """Quitter l'application et détruit l'armée stockée en mémoire et la liste de carac."""
        MaFen.unused(args)
        self.quit()
        self.destroy()

    @staticmethod
    def unused(args):
        """Méthode statique car elle n'effectue aucun changement sur la classe ou l'objet manipulé. Le but de cette
        méthode est de régler le warning concernant le paramètre args passé aux méthodes lors d'un évènement sur le
        clavier. Elle ne renvoi rien et n'effectue rien."""
        pass

    @classmethod
    def reset(cls):
        """Méthode de classe permettant de réinitialiser les armées de tous les joueurs contenues dans les attributs de
        classe."""
        MaFen.armeeSolo = A.Armee()
        MaFen.armeej1 = A.Armee()
        MaFen.armeej2 = A.Armee()
        MaFen.armeeOpti = A.Armee()

    @classmethod
    def reinitialiser_troupes(cls):
        """Permet de réinitialiser les valeurs du dictionnaire troupes.
        La méthode est déclarée comme méthode de classe car elle ne travaille que sur les attributs de classe."""
        list_troupes = Tr.Troupe.carac.keys()
        for elem in list_troupes:
            MaFen.troupes[elem] = 0
