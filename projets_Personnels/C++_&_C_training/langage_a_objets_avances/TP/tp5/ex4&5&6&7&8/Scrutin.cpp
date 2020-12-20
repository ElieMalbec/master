#include "Scrutin.hpp"

Scrutin::Scrutin(){

}

Scrutin::Scrutin(int nbBureaux, int nbOptions){
	nbBureauxVote = nbBureaux;
	nbOptionsVote = nbOptions;
	urnes = new Urne[nbBureauxVote];
}

Scrutin::~Scrutin(){
	delete [] urnes;
}