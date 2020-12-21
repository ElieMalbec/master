#include <string>
#include <iostream>
#include <iterator>
#include <map>

using std::string;
using std::cout;
using std::endl;

bool	isEven(const int &nb){
	return (nb % 2 == 0);
}


int main(){
	int x;
	std::cout << "choisir un nombre : ";
	std::cin >> x;
	std::string s = (isEven(x) == true) ? "Il est pair" : "Il est impair" ;
	std::cout << s << "\n";

	return 0;
}
