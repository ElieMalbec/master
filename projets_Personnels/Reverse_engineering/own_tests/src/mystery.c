/*#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void){

    return 0;
}*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int sum(int a, int b){
    return a + b;
}

int main(void){
    int a = 5;
    int b = 3;
    printf("Sum : %d", sum(a,b));
    return 0;
}