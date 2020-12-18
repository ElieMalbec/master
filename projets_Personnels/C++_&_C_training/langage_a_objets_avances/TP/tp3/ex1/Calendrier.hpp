#ifndef CALENDRIER_HPP
#define CALENDRIER_HPP


class Calendrier {
    Date date;
    Horloge horloge;

    public :
    Calendrier(Date &d, Horloge &h);

    Date& getDate();
    Horloge& getHorloge();
    friend std::ostream& operator<<(std::ostream o, Calendrier c);
};

#endif