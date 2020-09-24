# -*- coding: utf-8 -*-
"""Module consacré à l'optimisateur permettant de concevoir une armée plus performante que la norme. Il va prendre la
forme d'un algorithme génétique en utilisant des notions telles que : population, sélection, gène, croisements
multi-points.
En raison du fait que nous souhaitons obtenir une unique armée performante et non une population entière d'armée de ce
type, nous allons légèrement modifier le schéma traditionnel d'un algorithme génétique."""

import moteurCombat as MC
import Troupe
import Armee
import copy
import time  # Pour execution time

start_time = time.time()


def une_armee_et_ses_victoires(nombre_troupes, nombre_tests):
    """Cette fonction a pour objectif de créer une armée et de tester sa performance en lui faisant affronter un certain
    nombre d'adversaires. On la renvoie avec son nombre de victoires.
    Cette fonction est utilisée dans le cadre de l'IA Forte."""
    compteur = 0
    nbr_victoires = 0
    armee1 = Armee.Armee()
    armee1.former_armee_aleatoire(nombre_troupes)
    while compteur < nombre_tests:
        carmee1 = copy.deepcopy(armee1)
        armee2 = Armee.Armee()
        armee2.former_armee_aleatoire(nombre_troupes)
        combat = MC.moteur_de_combat(carmee1, armee2)
        if combat == 1:
            nbr_victoires = nbr_victoires + 1
        compteur = compteur + 1
    return [armee1, nbr_victoires]


def population_simple(taille_pop, nombre_troupes):
    """Cette fonction va créer une population composée d'individus (des armées) créé(e)s aléatoirement, et la renvoyer.
    Nous allons ensuite pouvoir traiter cette population qui est la première partie de la composition
    de notre algorithme génétique."""
    pop = []
    i = 0
    while i < taille_pop:
        armee = Armee.Armee()
        armee.former_armee_aleatoire(nombre_troupes)
        pop.append(armee)
        i += 1
    return pop


def population_evoluee(taille_pop, nombre_troupes, nombre_tests):
    """Création d'une population évoluée, composée d'armées ayant déjà remporté un certain nombre de combats. Ce type de
    population de départ sera utilisée dans le cadre de l'IA Forte."""
    pop = []
    i = 0
    while i < taille_pop:
        a = une_armee_et_ses_victoires(nombre_troupes, nombre_tests)
        # Si l'armée est parvenue à remporter la moitié ou plus de ses combats, alors elle est considérée comme
        # semi-performante.
        if a[1] >= (nombre_tests // 2):
            pop.append(a[0])
            i += 1
    return pop


def afficher_pop(pop):
    """Fonction permettant d'afficher la population d'armée dans le cas où c'est nécessaire pour les tests."""
    for i in range(len(pop)):
        Armee.afficher_armee(pop[i])


def tournoi_pop_simple(pop):
    """Cette fonction va gérer l'affrontement des armées côtes à côtes dans une population. Ainsi, la population que
    nous obtiendrons après utilisation aura la longueur de la population de départ divisée par 2.
    Il ne restera que les meilleures. Cette fonction est primordiale à l'application du processus de la sélection par
    tournoi. Elle retourne un tableau d'objets de type Armee."""
    plus_fortes = []
    i = 0
    if len(pop) > 2:
        while i + 1 < len(pop):
            carmee1 = copy.deepcopy(pop[i])
            carmee2 = copy.deepcopy(pop[i + 1])
            combat = MC.moteur_de_combat(carmee1, carmee2)
            if combat == 1:
                plus_fortes.append(pop[i])
                i = i + 2
            elif combat == 2:
                plus_fortes.append(pop[i + 1])
                i = i + 2
            elif combat == -1:
                plus_fortes.append(pop[i])
                i = i + 2

    elif len(pop) == 2:
        carmee1 = copy.deepcopy(pop[0])
        carmee2 = copy.deepcopy(pop[1])
        combat = MC.moteur_de_combat(carmee1, carmee2)
        if combat == 1:
            plus_fortes.append(pop[0])
        elif combat == 2:
            plus_fortes.append(pop[1])
        elif combat == -1:
            plus_fortes.append(pop[0])

    # Nous ne gérons pas le cas où len(pop)<2 car il n'arrivera jamais en raison du choix de la forme d'utilisation de
    # l'algorithme.
    return plus_fortes


def organisation_tournoi_simple(pop):
    """Cette fonction organise un tournoi au sein d'une population en se basant sur la fonction précédente. On suppose
    que la taille de la population de départ sera supérieure à 8 et égale à une puissance de 2 pour faciliter le calcul
    du vainqueur. Le tournoi est organisé de la même manière qu'un tournoi de sport ou de jeu : des éliminatoires à
    l'issue desquelles il ne restera que huit armées, un quart de finale avec pour résultat les quatre armées gagnantes,
    les demies finales d'où ressortiront les deux meilleures, et enfin la finale pour départager les deux armées.
    Cette fonction retourne un objet de type Armee."""

    # print("Voici les inscris pour ce tournoi : \n")
    # print("Débutons le tournoi : \n")
    # print("Phases éliminatoires : \n")
    eliminatoires = tournoi_pop_simple(pop)
    while len(eliminatoires) > 8:
        eliminatoires = tournoi_pop_simple(eliminatoires)
    # print("Quart finale : \n")
    quart = tournoi_pop_simple(eliminatoires)
    # print("Demi finale \n")
    demi = tournoi_pop_simple(quart)
    # print("DEMI")
    # print("Finale \n")
    # print("Voici notre vainqueur :\n")
    finale = tournoi_pop_simple(demi)
    # print("FINALE")
    return finale[0]


def des_armees_victorieuses(taille_pop, nombre_troupes, armees_obtenues):
    """Cette fonction renvoie un tableau d'armées (dont le nombre est paramétré) ayant remporté un tournoi au sein
    d'une population dont le nombre est lui aussi paramétré, que l'on choisit en fonction du besoin."""
    armees = []
    i = 0
    while i < armees_obtenues:
        pop = population_simple(taille_pop, nombre_troupes)
        tournoi = organisation_tournoi_simple(pop)
        armees.append(tournoi)
        i = i + 1
    return armees


def championnats_departementaux(nombre_participants, nombre_troupes, classee):
    """Championnats départementaux"""
    # print("Les championnats départementaux : \n")
    if classee == 0:
        participants = population_simple(nombre_participants, nombre_troupes)
    else:
        participants = population_evoluee(nombre_participants, nombre_troupes, classee)
    resultat = organisation_tournoi_simple(participants)
    return resultat


def championnats_regionaux(taille_pop, nombre_troupes, nombre_departements, classee):
    """Championnats régionaux"""
    # print("Les championnats régionaux : \n")
    vainqueurs_departementaux = []
    i = 0
    while i < nombre_departements:
        departementaux = championnats_departementaux(taille_pop, nombre_troupes, classee)
        vainqueurs_departementaux.append(departementaux)
        i = i + 1
    if nombre_departements >= 8:
        resultat = organisation_tournoi_simple(vainqueurs_departementaux)
        # print("Le vainqueur et représentant régional est : \n")
        return resultat
    else:
        resultat = tournoi_pop_simple(vainqueurs_departementaux)
        # print("Le vainqueur et représentant régional est : \n")
        return resultat[0]


def championnats_nationaux(taille_pop, nombre_troupes, nombre_regions, nombre_departements, classee):
    """Championnats nationaux"""
    # print("Les championnats nationaux : \n")
    i = 0
    vainqueurs_regionaux = []
    while i < nombre_regions:
        regionaux = championnats_regionaux(taille_pop, nombre_troupes, nombre_departements, classee)
        vainqueurs_regionaux.append(regionaux)
        i = i + 1
    if nombre_regions >= 8:
        resultat = organisation_tournoi_simple(vainqueurs_regionaux)
        # print("Le vainqueur et représentant national est : \n")
        return resultat
    else:
        resultat = tournoi_pop_simple(vainqueurs_regionaux)
        # print("Le vainqueur et représentant national est : \n")
        return resultat[0]


def championnats_mondiaux(taille_pop, nombre_troupes, nombre_pays, nombre_regions, nombre_departements, classee):
    """Championnats mondiaux"""
    # print("Les championnats mondiaux :\n")
    i = 0
    vainqueurs_nationaux = []
    while i < nombre_pays:
        champion_national = championnats_nationaux(taille_pop, nombre_troupes, nombre_regions, nombre_departements,
                                                   classee)
        vainqueurs_nationaux.append(champion_national)
        i = i + 1
    if nombre_pays >= 8:
        resultat = organisation_tournoi_simple(vainqueurs_nationaux)
        # print("Le vainqueur et champion du monde est : \n")
        # Armee.afficher_armee(resultat)
        return resultat
    else:
        resultat = tournoi_pop_simple(vainqueurs_nationaux)
        # print("Le vainqueur et champion du monde est : \n")
        # afficher_pop(resultat)
        return resultat[0]


def des_champions_du_monde(nombre_champions, taille_armee, classee):
    """Championnats mondiaux"""
    i = 0
    des_champions = []
    while i < nombre_champions:
        champ = championnats_mondiaux(16, taille_armee, 16, 16, 16, classee)
        des_champions.append(champ)
        i += 1
    return des_champions


def croisement(armee1, armee2, nombre_troupes):
    """Fonction effectuant des croisements entre deux armées. Nous prenons la partie haute des deux armées et nous les
    interchangeons."""
    i = 0
    while i < 10:
        for troupe in Troupe.Troupe.carac:
            if len(armee1.troupes[troupe]) == 0:
                if len(armee2.troupes[troupe]) != 0:
                    a = armee1.troupes[troupe]
                    armee1.troupes[troupe] = armee2.troupes[troupe]
                    armee2.troupes[troupe] = a
            else:
                a = armee2.troupes[troupe]
                armee2.troupes[troupe] = armee1.troupes[troupe]
                armee1.troupes[troupe] = a
            i = i + 1
            if i >= 10:
                break
    # Ici, nous nous assurons que le croisement n'a pas trop altéré le nombre de points totaux. Si tel est le cas, le
    # croisement ne renvoie rien. Nous nous donnons une marge de 10% du nombre total de troupes.
    p1 = armee1.COUT
    p2 = armee2.COUT
    p1_pt = p1 - nombre_troupes
    p2_pt = p2 - nombre_troupes
    autorise = int(nombre_troupes * (1 / 10))
    if p1_pt <= autorise and p2_pt <= autorise:
        if p1_pt > p2_pt:
            return armee1
        elif p1_pt == p2_pt:
            armee = tournoi_pop_simple([armee1, armee2])
            return armee[0]
        else:
            return armee2
    elif p1_pt > autorise >= p2_pt:
        return armee2
    elif p1_pt <= autorise < p2_pt:
        return armee1
    elif p1_pt > autorise and p2_pt > autorise:
        return None


def evaluation(armee_testee, nombre_tests, nombre_troupes):
    """On créé une fonction évaluation qui va permettre d'évaluer les capacités d'une armée en lui faisant affronter un
    certain nombre d'adversaires. Le but est de s'assurer qu'une armée optimisée l'est vraiment. Le nombre de tests
    diffère en fonction du niveau de l'IA choisit par l'utilisateur."""
    i = 0
    victoires = 0
    while i < nombre_tests:
        carmee = copy.deepcopy(armee_testee)
        armee2 = Armee.Armee()
        armee2.former_armee_aleatoire(nombre_troupes)
        combat = MC.moteur_de_combat(carmee, armee2)
        if combat == 1:
            victoires = victoires + 1
        i = i + 1
        if i == nombre_tests:
            break
    if victoires >= nombre_tests // 3:
        return True
    else:
        return False


def algorithme_genetique_parametre(nombre_troupes, faible_ou_forte, niveau_ia, croisee, evalu):
    """Algorithme génétique gérant la totalité du processus en fonction de la demande de l'utilisateur."""
    armee = Armee.Armee()
    eval = True
    if faible_ou_forte == 0:
        classee = 0
    else:
        # Nous fixons les combats de base pour les armées formant les premières populations à 10.'''
        classee = 10

    # Nous choisissons d'effectuer des championnats avec une population de départ de 16 armées à chaque fois pour simplifier
    # la gestion du tournoi et éviter un temps de calcul trop long.
    if niveau_ia == 0:
        if croisee == 0:
            armee = championnats_departementaux(16, nombre_troupes, classee)
        else:
            armee1 = championnats_departementaux(16, nombre_troupes, classee)
            armee2 = championnats_departementaux(16, nombre_troupes, classee)
            armee = croisement(armee1, armee2, nombre_troupes)
            # Si le croisement ne renvoie rien, alors la fonction a trop altéré le nombre de points autorisés. Dans ce
            # cas, nous recommencons le processus.
            if armee is None:
                while armee is None:
                    armee1 = championnats_departementaux(16, nombre_troupes, classee)
                    armee2 = championnats_departementaux(16, nombre_troupes, classee)
                    armee = croisement(armee1, armee2, nombre_troupes)
                    if armee is not None:
                        break
        if evalu == 1:
            eval = evaluation(armee, 10, nombre_troupes)
    elif niveau_ia == 1:
        if croisee == 0:
            armee = championnats_regionaux(16, nombre_troupes, 16, classee)
        else:
            armee1 = championnats_regionaux(16, nombre_troupes, 16, classee)
            armee2 = championnats_regionaux(16, nombre_troupes, 16, classee)
            armee = croisement(armee1, armee2, nombre_troupes)
            if armee is None:
                while armee is None:
                    armee1 = championnats_regionaux(16, nombre_troupes, 16, classee)
                    armee2 = championnats_regionaux(16, nombre_troupes, 16, classee)
                    armee = croisement(armee1, armee2, nombre_troupes)
                    if armee is not None:
                        break
        if evalu == 1:
            eval = evaluation(armee, 20, nombre_troupes)
    elif niveau_ia == 2:
        if croisee == 0:
            armee = championnats_nationaux(16, nombre_troupes, 16, 16, classee)
        else:
            armee1 = championnats_nationaux(16, nombre_troupes, 16, 16, classee)
            armee2 = championnats_nationaux(16, nombre_troupes, 16, 16, classee)
            armee = croisement(armee1, armee2, nombre_troupes)
            if armee is None:
                while armee is None:
                    armee1 = championnats_nationaux(16, nombre_troupes, 16, 16, classee)
                    armee2 = championnats_nationaux(16, nombre_troupes, 16, 16, classee)
                    armee = croisement(armee1, armee2, nombre_troupes)
                    if armee is not None:
                        break
        if evalu == 1:
            eval = evaluation(armee, 30, nombre_troupes)
    elif niveau_ia == 3:
        if croisee == 0:
            armee = championnats_mondiaux(16, nombre_troupes, 16, 16, 16, classee)
        else:
            armee1 = championnats_mondiaux(16, nombre_troupes, 16, 16, 16, classee)
            armee2 = championnats_mondiaux(16, nombre_troupes, 16, 16, 16, classee)
            armee = croisement(armee1, armee2, nombre_troupes)
            if armee is None:
                while armee is None:
                    armee1 = championnats_mondiaux(16, nombre_troupes, 16, 16, 16, classee)
                    armee2 = championnats_mondiaux(16, nombre_troupes, 16, 16, 16, classee)
                    armee = croisement(armee1, armee2, nombre_troupes)
                    if armee is not None:
                        break
        if evalu == 1:
            eval = evaluation(armee, 40, nombre_troupes)
    return [armee, eval]
