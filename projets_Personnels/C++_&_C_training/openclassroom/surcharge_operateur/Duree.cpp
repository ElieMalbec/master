#include "Duree.h"
class Duree {
  Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
  {
  }
  bool Duree::estEgal(Duree const& b) const
  {
    return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);     //Teste si a.m_heure == b.m_heure etc.
  }
  bool operator==(Duree const& a, Duree const& b){
    return a.estEgal(b);
  }
};
