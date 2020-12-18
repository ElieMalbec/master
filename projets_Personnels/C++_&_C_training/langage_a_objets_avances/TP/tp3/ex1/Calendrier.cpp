#include "Calendrier.hpp"
#include "Date.hpp"
#include "Horloge.hpp"

Calendrier::Calendrier(Date &d, Horloge &h) {
    date = d;
    horloge = h;
}

Date& Calendrier::getDate(){
    return this->date;
}

Horloge& Calendrier::getHorloge(){
    return this->horloge;
}

std::ostream& operator<<(std::ostream &o, Calendrier &c) {
    o << c.getDate() << " " << c.getHorloge();
    return o;
}