#include <iostream>
#include <string>
/*A revoir !!!*/


//possible d'utiliser des enums
enum class Famille {
    Carreau, Pique, Coeur, Rectangle
};

enum class Color {
    Black, Red
};

enum class Value {
    deux = 2, trois = 3, quatre = 4, cinq = 5, six = 6, sept = 7, huit = 8, neuf = 9, dix = 10, onze = 11, douze = 12, treize = 13, quatorze = 14
};
struct carte {
    Color couleur;
    Value valeur;
    Famille famille;
};
constexpr int Valet = 11;
constexpr int Dame  = 12;
constexpr int Roi   = 13;
constexpr int As    = 14;

void    print( struct carte *c){
    std::cout << static_cast<std::string>(c->valeur)  << " " << static_cast<std::string>(c->couleur) << " " << static_cast<std::string>(c->famille) << "\n";
}

std::ostream &operator<<(std::ostream &o, const Famille &f){


}

int main(){
    carte c;
    c.couleur    = Color::Red;
    c.famille    = Famille::Coeur;
    c.valeur     = Value::huit;

    print(&c);
}