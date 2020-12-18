#include <iostream>
#include "BoxInt.hpp"
#include "test.cpp"

using std::string;
using std::cout;
using std::endl;


int main(){
	BoxInt monTest (42);
	cout << "alive 42 : " << monTest.alive_count() << "\n";
	monTest.print ();
	monTest.set (5);
	monTest.print ();
	fonction1(monTest);
	monTest.print ();
	fonction2 (& monTest);
	monTest.print ();
	fonction3(monTest);
	monTest.print ();

	cout << "---------\n";
	cout << "alive beg : " << monTest.alive_count() << "\n";
	un_test();
	cout << "alive end : " << monTest.alive_count() << "\n";
	std::cout << monTest;
	return 0;
}

//Question 6 ?
