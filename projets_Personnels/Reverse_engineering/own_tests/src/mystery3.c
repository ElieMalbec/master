#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

int main(void){
    int *arr = malloc(sizeof(int) * SIZE);
    for (unsigned int i = 0; i < SIZE; ++i){
        arr[i] = i * i; 
    }
    return 0;
}