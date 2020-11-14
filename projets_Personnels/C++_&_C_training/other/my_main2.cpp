#include <string>
#include <iostream>
#include <iterator>
#include <map>

using std::string;
using std::cout;
using std::endl;


int main(int argc, char **argv){
	const char* s1 = "word";
	const char s2[] = "word";
	cout << sizeof(s1) << " " << sizeof(s2) << endl;
	//assert(sizeof(s1) != sizeof(s2));

	return 0;
}
