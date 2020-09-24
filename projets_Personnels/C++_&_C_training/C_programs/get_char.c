#include <stdio.h>

/*
int main(void){
    char c = getchar();//if write 2 char the second will be in d
    char d = getchar();

    putchar(c);//
    putchar(d);
    return 0;
}
*/

int main(void){
    int c;

    printf("%d", EOF);
    printf("%d", getchar() != EOF);
    /*
    while ((c = getchar()) != EOF){
        putchar(c);
    }
    */
}