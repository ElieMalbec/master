#include <string>
#include <iostream>
#include <iterator>
#include <map>

using std::string;
using std::cout;
using std::endl;

class Entity {
	public :
	int x;

	Entity()
		: x(0) {}
	Entity (int value)
		:x(value) {}

	Entity operator+(const Entity &other) const 
	{
		return (x + other.x);
	}
};

std::ostream& operator<<(std::ostream &stream, const Entity &other){
	stream << other.x;
	return stream;
}

int main(void){
	Entity e(10);
	Entity b(8);
	Entity c = e + b;


	cout << c+b << endl;
	return 0;
}
