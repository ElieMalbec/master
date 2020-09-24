#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//use ft_putnbr instead of printf
//use your own atoi
//./a.out 42 - --+-20toto12 not working because of the atoi i use
//use a makefile to create a executable called do-op
void    check_division_by_zero(int a, int b);
void    check_operator(int a, int b, char *str);


void    check_division_by_zero(int a, int b){
    if (b == 0){
        printf("Stop : division by zero");
    }
    else {
        printf("%d", a/b);
    }
}

void    check_modulo_by_zero(int a, int b){
    if (b == 0){
        printf("Stop : modulo by zero");
    }
    else {
        printf("%d", a%b);
    }
}

void    check_operator(int a, int b, char *str){
    if (str[0] == '+' && str[1] == '\0'){
        printf("%d", a+b);
    }
    else if (str[0] == '-' && str[1] == '\0'){
        printf("%d", a-b);
    }
    else if (str[0] == '*' && str[1] == '\0'){
        printf("%d", a*b);
    }
    else if (str[0] == '/' && str[1] == '\0'){
        check_division_by_zero(a, b);
    }
    else if (str[0] == '%' && str[1] == '\0'){
        check_modulo_by_zero(a, b);
    }
    else {
        printf("0");
    }
}

//modify it to use an array of pointer to func
int main(int argc, char **argv){
    if (argc != 4) return 0;

    int a = atoi(argv[1]);
    int b = atoi(argv[3]);

    check_operator(a, b, argv[2]);

    return 0;
}