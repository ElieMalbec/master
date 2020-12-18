#include <iostream>
#include "Horloge.hpp"
#include "Date.hpp"
#include "Calendrier.cpp"

using std::cout;
int main(void){
    int ho,m,s;
    //std::cin >> ho >> m >> s;
    Horloge h(ho = 3, m = 45, s = 12);

    std::cout << h << "\n";
    h.tick();
    std::cout << h << "\n";

    Date d{11, 29};
    std::cout << d << "\n";
    d.nextday();
    std::cout << d << "\n";

    Calendrier c(d, h);
    std::cout << c.getDate() << " " << c.getHorloge();

}