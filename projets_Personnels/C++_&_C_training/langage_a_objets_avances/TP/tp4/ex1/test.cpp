#include "BoxInt.hpp"
// #include <iostream>

void fonction1(BoxInt t) {
    t.set (36);
}

void fonction2(BoxInt *t) {
    t->set (666);
}

void fonction3(BoxInt &t) {
    t.set (1);
}

/* void fonction4(const BoxInt &t) {
    t.set (1);
} */

void un_test ()
{
    BoxInt un_int (42);
    BoxInt un_autre_int = un_int;
    //std::cout << un_autre_int.alive_count() << "\n";
    return;
}