#include <iostream>
#include "Vector.hpp"

int main(){
	Vector v{8};

	v.print();
	v.set_at(0, 3);
	v.set_at(1, 4);
	v.set_at(2, 5);
	v.set_at(3, 8);
	v.set_at(4, 9);
	v.set_at(5, 10);
	v.set_at(6, 11);
	v.set_at(7, 12);
	v.set_at(8, 12);
	v.set_at(-2, 12);

	std::cout << v.get_at(7) << "\n";
	std::cout << v.get_at(2) << "\n";
	std::cout << v.get_at(-7) << "\n";
	std::cout << v.get_at(77) << "\n";

	std::cout << "memory taken = " << v.memoryTaken() << "\n";
	v.push_back(35);
	v.print();
	std::cout << "memory taken = " << v.memoryTaken() << "\n";
	v.push_front(101);
	v.print();
	std::cout << "memory taken = " << v.memoryTaken() << "\n";
	
	std::cout << v.pop_back() << "\n";
	v.print();
	std::cout << "memory taken = " << v.memoryTaken() << "\n";
	
	std::cout << v.pop_front() << "\n";
	v.print();
	std::cout << "memory taken = " << v.memoryTaken() << "\n";
	

	/* srand(time(NULL));
	std::cout << rand() << "\n"; */
	
	return 0;
}

//Question 5, 6, 7