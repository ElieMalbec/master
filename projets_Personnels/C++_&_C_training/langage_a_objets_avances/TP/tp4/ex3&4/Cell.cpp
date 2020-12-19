#include "Cell.hpp"


Cell::Cell() : Cell(0){}

Cell::Cell(int value){
	contenu = value;
	pred = nullptr;
	next = nullptr;
}

void    connect(Cell& first, Cell& second){
	first.next 	= &second;
	second.pred = &first;
}

void    Cell::connect(Cell& second){
	this->next = &second;
	second.pred = this;
}

void    Cell::disconnect_next(){
	this->next = nullptr;
}

void    Cell::disconnect_previous(){
	this->pred = nullptr;
}

int     Cell::getContenu(){
	return contenu;
}

Cell*   Cell::getNext(){
	return next;
}

void    Cell::setContenu(int val){
	contenu = val;
}

void    Cell::setNext(Cell *c){
	this->next = c;
}

void    Cell::setPred(Cell *c){
	this->pred = c;
}