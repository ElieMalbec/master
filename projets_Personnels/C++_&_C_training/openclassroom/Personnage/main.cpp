#include "Personnage.h"
#include "Arme.h"

int main()
{
    Personnage david, goliath;
    //Personnage copie(goliath)//crée un Personnage copie qui est la copie de goliath (constructeur de copie)

    //Au combat !
    goliath.attaquer(david);
    david.boirePotionDeVie(20);
    goliath.attaquer(david);
    david.attaquer(goliath);
    goliath.changerArme("Double hache tranchante vénéneuse de la mort", 40);
    goliath.attaquer(david);

    //Temps mort ! Voyons voir la vie de chacun…
    std::cout << "David" << std::endl;
    david.afficherEtat();
    std::cout << std::endl << "Goliath" << std::endl;
    goliath.afficherEtat();

    return 0;
}
