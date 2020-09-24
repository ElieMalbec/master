#include <stdio.h>
#include <unistd.h>

//What i want not working 
int main(void){
    printf("Input : \n");
    char a = '\0';
    while (a == '\0'){
        printf("waiting : \n");
        sleep(2);
        scanf("%c", &a);
    }
    printf("Input : \n");

    return 0;
}