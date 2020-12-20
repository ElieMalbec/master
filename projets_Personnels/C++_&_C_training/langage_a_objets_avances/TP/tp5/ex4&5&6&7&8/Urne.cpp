#include "Urne.hpp"

Urne::Urne(){
	numBureauVote++;
	//votes = new int[nbOptionsVote]; // dépend du nb d'options de vote
	//monScrutin = mon scrutin qui créé un bureaux de vote;
}
Urne::~Urne(){
	numBureauVote--;
	delete [] votes;
}

bool Urne::voter(int choix){

}

int Urne::numBureauVote = 0;
