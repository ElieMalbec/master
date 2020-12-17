#include "UE.hpp"
#include "Etudiant.hpp"

using namespace std;

int main() {

  //i1 a pour numéro d'étudiant 0
  const Inscrit i1, i2{"Coco", "Luc", 4};
  cout << "****** INSCRITS ****" << endl;
  cout << i1 << i2;
  
  Etudiant e1{i1}, e2{i2}, e3{"Bongo", "Lucie", 7};
  cout << endl << "****** ETUDIANTS ****" << endl;
  cout << e1 << e2 << e3;
  
  UE u{"IF435"};
  u.ajout_etudiant(i1);
  u.ajout_etudiant(i2);
  u.ajout_note(17.5, 0, 0.5);
  u.ajout_note(7.5, 0, 0.5);
  u.ajout_note(10.5, 4, 0.5);
  u.ajout_note(15, 4, 0.5);
  cout << endl << "****** UE ****" << endl;
  cout << u;
  cout << "MOYENNE DE IF435 : " << u.moyenne() << endl;

  UE v{"IF876"};
  vector<float> coefs={0.2, 0.3, 0.5};
  v.ajout_etudiant(i1);
  v.ajout_etudiant(i2);
  v.set_coefs(coefs);
  v.ajout_note(14, 0);
  v.ajout_note(7.5, 0);
  v.ajout_note(13.5, 0);
  v.ajout_note(10.5, 4);
  v.ajout_note(15, 4);
  v.ajout_note(19, 4);
  cout << endl << "****** UE ****" << endl;
  cout << v;
  cout << "MOYENNE DE IF876 : " << v.moyenne() << endl;

  Etudiant e4{i1};
  e4.synchro(u);
  e4.synchro(v);
  cout << endl << "****** ETUDIANT ****" << endl;
  cout << e4;

  v.ajout_note(7.5, 0);
  coefs={0.1, 0.3, 0.5, 0.1};
  v.set_coefs(coefs);
  cout << e4;
  e4.synchro(v);
  cout << endl << "****** SYNCHRONISATION ETUDIANT ****" << endl;
  cout << e4;

  return 0;
}
