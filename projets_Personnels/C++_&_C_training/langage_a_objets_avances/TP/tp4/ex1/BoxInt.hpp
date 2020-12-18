#ifndef BOXINT_HPP
#define BOXINT_HPP
#include <iostream>
class BoxInt {
	int entier;
	static int nbBoxes;

	public:
	BoxInt(int value);
	BoxInt(const BoxInt &cp);
	~BoxInt();

	int get();
	void set(int value);
	void print();
	int alive_count();
	friend std::ostream& operator<<(std::ostream &o, BoxInt &box);
};
#endif