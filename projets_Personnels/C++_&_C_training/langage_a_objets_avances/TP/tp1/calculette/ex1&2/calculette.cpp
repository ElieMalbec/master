#include <string>
#include <iostream>
#include <iterator>
#include <map>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(){
	srand(time(nullptr));
	int nbRandOne = rand() / 1000;
	int nbRandTwo = rand() / 1000;
	int toFind = nbRandOne + nbRandTwo;
	std::cout << "toFind: " << toFind << std::endl;

	int result;
	while (true){
		cin >> result;
		if (result == toFind){
			std::cout << "Good Job !\n";
			break;
		}
		else if (result > toFind){
			std::cout << "It's smaller !\n";
		}
		else {
			std::cout << "It's bigger !\n";	
		}
	}
	return 0;
}
