#include <string>
#include <iostream>
#include <iterator>
#include <map>

using std::string;
using std::cout;
using std::endl;


void test(int *p, int *q) {
	cout << "p : " << *p << " " << p << "  & q " << *q << " " << q << endl;
	*p = 3;
	p = q;
	cout << "p : " << *p << " " << p << "  & q " << *q << " " << q << endl;
}

int main(void){
	int *p, *q;
	int a = 10,b = 8;
	cout << &a << " " << &b << endl;
	p = &a;
	q = &b;
	test(p,q);
	cout << "p : " << *p << " " << p << "  & q" << *q << " " << q << endl;
	return 0;
}
