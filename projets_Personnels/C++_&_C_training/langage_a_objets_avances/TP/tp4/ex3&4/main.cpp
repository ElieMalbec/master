#include <iostream>
#include "Cell.hpp"
#include "List.hpp"

using std::string;
using std::cout;
using std::endl;


int main(){
	Cell c;
	Cell d(5);
	Cell e(12);

	c.connect(d);
	connect(d,e);

	List l;
	l.setFirst(&c);
	l.setLast(&e);
	std::cout << "length : " << l.lenght() << "\n";
	std::cout << "get (2): " << l.get(2) << "\n";
	std::cout << "find good: " << l.find(5) << "\n";
	std::cout << "find miss : " << l.find(35) << "\n";

	l.set(1, 15);
	std::cout << "set : " << l.get(1) << "\n";

	l.insert(1, 100);
	std::cout << "length : " << l.lenght() << "\n";
	std::cout << "get (1): " << l.get(1) << "\n";
	std::cout << "get (2): " << l.get(2) << "\n";
	std::cout << "get (3): " << l.get(3) << "\n";
	std::cout << "get (4): " << l.get(4) << "\n";
	return 0;
}
