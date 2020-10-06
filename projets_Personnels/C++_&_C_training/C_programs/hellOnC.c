#include <stdio.h>


void do_stuff(int a, int * b) {
    printf("a & b first time calling the function %d %d\n", a, *b);
    a = 5;
    printf("a & b when a=5 : %d %d\n", a, *b);
    b = a++ * 2;
    printf("a & b after calculation %d %d\n", a, *b);
    ++b;
    printf("a & b after ++b %d %d\n", a, *b);
}

void main() {
    int a = 10;
    int b = 20;
    printf("a & b before calling function %d %d\n", a, b);
    do_stuff(a, &b);
    printf("a & b after calling function %d %d\n", a, b);
    // what is a right here?
    // what is b right here?
}