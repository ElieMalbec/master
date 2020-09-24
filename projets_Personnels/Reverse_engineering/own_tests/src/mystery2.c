#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int arr[] = {5,4,3,8,7,4};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}