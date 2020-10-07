#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv){
    if (argc != 2){
        printf("not enough or too much args\n");
        return 1;
    }

    int nb = atoi(argv[1]);

    int sum = 0;
    if (nb < 0) nb = abs(nb);
    while (nb != 0){
        sum = sum + nb % 10;
        nb = nb / 10;
    }
    printf("sum : %d & nb : %d\n", sum, nb);
    return 0;
}