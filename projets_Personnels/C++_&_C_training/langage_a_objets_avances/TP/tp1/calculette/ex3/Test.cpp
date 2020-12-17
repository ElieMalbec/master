#include <iostream>
#include "Point.hpp"

int main(){
    Point a(4, 4);
    Point b(8, 1);

    a.print();
    b.print();

    a.setX(-5);
    a.setY(3);

    a.print();

    std::cout << distance(a, b) << "\n";
}