#include <string>
#include <iostream>
#include <iterator>
#include <map>

using std::string;
using std::cout;
using std::endl;


void	incrementer(int &nb){
	nb++;
}

void	swap(int &a, int &b){
	a ^= b;
	b ^= a;
	a ^= b;
}

int main(){
	int x,y;
	std::cin >> x >> y;
	std::cout << "Valeur de x et y: " << x << " " << y << "\n";
	incrementer(x);
	incrementer(y);
	std::cout << "Valeur de x et y: " << x << " " << y << "\n";
	swap(x,y);

	std::cout << "Valeur de x et y: " << x << " " << y << "\n";

	return 0;
}
