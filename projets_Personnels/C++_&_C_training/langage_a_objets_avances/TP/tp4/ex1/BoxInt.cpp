#include "BoxInt.hpp"
#include <iostream>

BoxInt::BoxInt(int value){
	std::cout << "constructor called\n";
	entier = value;
	nbBoxes++;
}
BoxInt::~BoxInt(){
	std::cout << "destructor called\n";
	nbBoxes--;
}

BoxInt::BoxInt(const BoxInt &cp){
	std::cout << "copy constructor called\n";
	this->entier = cp.entier;
	nbBoxes++;
}
int BoxInt::get(){
	return entier;
}
void BoxInt::set(int value){
	entier = value;
}
void BoxInt::print(){
	std::cout << entier << "\n";
}

int BoxInt::alive_count(){
	return nbBoxes;
}

int BoxInt::nbBoxes = 0;

std::ostream& operator<< (std::ostream &o, BoxInt &box){
	o << "There is " << box.alive_count() << " objects and this one has the value " << box.get() << "\n";
	return o;
}