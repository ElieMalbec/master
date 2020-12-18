#ifndef DATE_HPP
#define DATE_HPP
#include <string>
class Date {
    std::string mois[12] = {"janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre"};
    int jours;
    int nbMois;

    public:
    Date(int mois, int jours);
    Date();
    void nextday();
    friend std::ostream& operator<<(std::ostream &o, Date &d);
};
#endif