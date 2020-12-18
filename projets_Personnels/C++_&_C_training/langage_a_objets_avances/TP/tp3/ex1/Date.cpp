#include "Date.hpp"
#include <iostream>

Date::Date(int m, int j){
    nbMois = m % 12;
    this->jours = j % 30;
}
Date::Date(){
    nbMois = 0;
    jours = 1;
}

void Date::nextday(){
    if (jours == 29){
        if (nbMois == 11){
            nbMois = 0;
            jours = 1;
        }
        else {
            nbMois++;
            jours = 1;
        }
    }
    else {
        jours++;
    }
}

std::ostream &operator<<(std::ostream& o, Date &d){
    o << "Nous sommes le " << d.jours << " " << d.mois[d.nbMois];
    return o;
}