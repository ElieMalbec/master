#include "Vector.hpp"
#include <iostream>

Vector::Vector(int taille){
	size = taille;
	tab = new int[taille];
	mem+= sizeof(this);
}

Vector::~Vector(){
	delete [] tab;
	mem-= sizeof(this);
}

void	Vector::print(){
	std::cout << "taille : " << size << " avec comme valeurs : ";
	for (int i = 0; i < size; i++){
		std::cout << tab[i] << (i == (size-1) ? ".\n" : ",");
	}
}

int		Vector::get_at(int index){

	return (index > size || index < 0 ? tab[0] : tab[index]);
}

void	Vector::set_at(int index, int value){
	if (index < size && index >= 0){
		tab[index] = value;
	}
	else {
		std::cout << "Index too big or too small ! \n";
	}
}

void	Vector::push_back(int value){
	int *new_array = new int[size + 1];
	int i;
	for (i = 0; i < size; i++){
		new_array[i] = tab[i];
	}
	new_array[i] = value;
	size++;
	delete [] tab;
	tab = new_array;
	mem++;
}

void	Vector::push_front(int value){
	int *new_array = new int[size + 1];
	int i;
	new_array[0] = value;
	for (i = 0; i < size; i++){
		new_array[i + 1] = tab[i];
	}
	size++;
	delete [] tab;
	tab = new_array;
	mem++;
}

int		Vector::memoryTaken(){
	return this->mem;
}
int		Vector::pop_back(){
	int last = tab[size - 1];
	int *new_array = new int[size-1];
	for (int i = 0; i < size-1; i++){
		new_array[i] = tab[i];
	}
	delete [] tab;
	tab = new_array;
	mem--;
	size--;
	return last;
}
int		Vector::pop_front(){
	int debut = tab[0];
	int *new_array = new int[size-1];
	for (int i = 1; i < size; i++){
		new_array[i-1] = tab[i];
	}
	delete [] tab;
	tab = new_array;
	mem--;
	size--;
	return debut;
}
int Vector::mem = 0;