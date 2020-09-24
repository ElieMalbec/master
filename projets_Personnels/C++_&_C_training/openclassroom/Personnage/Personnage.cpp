#include <string>

class Personnage {
private :
  int m_vie;
  int m_mana;
  std::string m_nomArme;
  int m_degatsArme;

public :
  Personnage() : m_vie = 100, m_mana = 100, m_nomArme = "Épée rouillée", m_degatsArme = 10{

  }
  Personnage(string nomArme, int degatsArme) : vie(100), mana(100),nomArme(nomArme), degatsArme(degatsArme){

  }
  Personnage(int nbVie, int nbMana) : vie(nbVie), mana(nbMana), nomArme("Épée rouillée"), degatsArme(10){

  }
  void recevoirDegats(int nbDegats){
    m_vie -= nbDegats;
    //On enlève le nombre de dégâts reçus à la vie du personnage
    if (m_vie < 0) //Pour éviter d'avoir une vie négative
    {
        m_vie = 0; //On met la vie à 0 (cela veut dire mort)
    }
  }
  void attaquer(Personnage &cible)
  {
    cible.recevoirDegats(m_arme.getDegats());
  }

   void boirePotionDeVie(int quantitePotion)
   {
     m_vie += quantitePotion;

     if (m_vie > 100) //Interdiction de dépasser 100 de vie
     {
       m_vie = 100;
     }
   }

   void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme)
   {
        m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
   }

   bool estVivant() const
   {
     return vie > 0;
   }
   void afficherEtat() const{
     cout << "Vie : " << m_vie << endl;
     cout << "Mana : " << m_mana << endl;
     m_arme.afficher();
   }

   int Arme::getDegats() const
   {
       return m_degats;
   }

};
