#include <iostream> //appel préprocesseur
#include "math.h"
//using namespace cout; //nommage


int main(void)
{
	/*
	std::cout << "Hello world!" << std::endl;
	cout << "Bonjour tout le monde !" << endl << "Comment allez-vous ?" << endl;
	char hi('a');
	string hi2("hello two");

	cout << hi << endl << hi2 << endl;

	int test(15);
	int &autre_test(test);
	cout << autre_test<< test << endl;
*/

/*
	string my_profession;
	cout << "What is your profession ?" << endl;
	cin >> my_profession; 								//ne permet pas de récupérer la ligne
	cout << my_profession << endl;
	cin.ignore();
	if (my_profession == "+") {
		cout << "+++"<<endl;
	}
*/

/*
	string fullname;
	cout << "What is your full name ?" << endl ;
	getline(cin, fullname); 							//can't use cin alone before, use ci.ignore();
	cout << "Your name is " << fullname << endl;
*/

/*
	double maths(25);
	cout << sqrt(maths) << endl;
	cout << sin(maths) << endl;
	cout << log10(maths) << endl;
	cout << pow(maths,2) << endl;
*/

/*
	std::cout << "i add two to 5 : " << addtwo(5) << std::endl;
*/

/*
	std::vector<double> my_notes;
	my_notes.push_back(5);
	my_notes.push_back(12);
	my_notes.push_back(15);
	my_notes.push_back(13);
	std::cout << "Votre moyenne : " << moyenne(my_notes) << std::endl;
*/

/*
	std::string my_string;
	my_string+="Hello ";
	std::cout << my_string << " Wait hello who ?" << std::endl;
	my_string+="young wolf";
	std::cout << my_string << ". I prefer that ! :)" << std::endl;
*/



/*
	std::string const name_of_file("./file.txt");
	std::ofstream my_file(name_of_file.c_str()); //std::ios::app
	if (my_file){
			my_file << "12 15 13.5 6.5 17";
			my_file.close();
	}
	else {
		std::cout << "the file did not load" << std::endl;
	}


	std::ifstream my_flux2("./file.txt");
	if (my_flux2){
			std::string word;
			std::vector<double> notes(5,0);
		//	std::cout << notes << std::endl;

				std::cin >> word; std::cout << word <<std::endl;
				notes[0] = std::stod(word);    std::cout << notes[0];/*
				std::cin >> notes[1];
				std::cin >> notes[2];
				std::cin >> notes[3];
				std::cin >> notes[4];//

				std::cout << "voici votre moyenne : " << moyenne(notes) << std::endl;

	}
	else {
		std::cout << "Error loading the file" << std::endl;
	}
*/

	int ageUtilisateur(16);
	int *ptr(0);

	ptr = &ageUtilisateur;

	std::cout << "L'adresse de 'ageUtilisateur' est : " << &ageUtilisateur << std::endl;
	std::cout << "La valeur de pointeur est : " << ptr << std::endl;
	std::cout << "La valeur de pointeur est : " << *ptr << std::endl;



	return 0;
}

int addtwo(int number){
	return number+2;
}

double moyenne(std::vector<double> &notes){
	int size = notes.size();
	double result = 0;
	for (int i(0); i< size; i++){
			result+=notes[i];
	}

	return (result/size) ;
}
