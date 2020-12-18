#include "Horloge.hpp"

Horloge::Horloge(int heure, int minutes, int secondes){
	int totalsec = secondes + (minutes * TIME_MIN) + (heure * TIME_HEURE);
	h = (totalsec / TIME_HEURE) % 24;
    min = (totalsec % TIME_HEURE) / TIME_MIN;
    sec = totalsec % TIME_MIN;
}

Horloge::Horloge() {
	h = 0;
	min = 0;
	sec = 0;
}


std::ostream &operator<<(std::ostream &o, Horloge &h){
	o << "Il est : " << h.h << " heures et " << h.min << " minutes et " << h.sec << " secondes";
	return o;
}

void Horloge::tick(){
	if (sec == 59){
		if (min == 59){
			if (h == 23){
				h = 0;
				min = 0;
				sec = 0;
			}
			else {
				h++;
				min = 0;
				sec = 0;
			}
		}
		else {
			min++;
			sec = 0;
		}
	}
	else {
		sec++;
	}
}
