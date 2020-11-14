#include <iostream>

int main(void){
	bool b = false;
	bool c = true;
	if (!(b)){ // means if b == false
		std::cout << !b << std::endl;
	}
	if (!(c)){
		std::cout << !c << std::endl;
	}
	return 0;
}
