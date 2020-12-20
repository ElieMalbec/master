#ifndef SCRUTIN_HPP
#define SCRUTIN_HPP
#include "Urne.hpp"


class Scrutin {
	int nbBureauxVote;
	int nbOptionsVote;
	Urne *urnes;

    public :
    Scrutin();
    Scrutin(int nbBureaux, int nbOptions);
    ~Scrutin();
	
};

#endif
