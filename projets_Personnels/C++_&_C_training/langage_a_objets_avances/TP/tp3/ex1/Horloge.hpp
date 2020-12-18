#ifndef HORLOGE_HPP
#define HORLOGE_HPP
constexpr int TIME_MIN      = 60;
constexpr int TIME_HEURE    = 3600;
#include <iostream>

class Horloge {
	int h;
	int min;
	int sec;

	public :
	Horloge(int heure, int minutes, int secondes);
    Horloge();

	friend std::ostream& operator<<(std::ostream &o, Horloge &h);

    void tick();
};
#endif