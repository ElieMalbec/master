#include "Arme.h"

class Arme
{
  private:
      std::string m_nom;
      int         m_degats;

  public:
      Arme::Arme() : m_nom("Épée rouillée"), m_degats(10)
      {

      }

      Arme::Arme(string nom, int degats) : m_nom(nom), m_degats(degats)
      {

      }

      void Arme::changer(string nom, int degats)
      {
          m_nom = nom;
          m_degats = degats;
      }

      void Arme::afficher() const
      {
          cout << "Arme : " << m_nom << " (Dégâts : " << m_degats << ")" << endl;
      }
};
