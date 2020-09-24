#include <stdio.h>

#define MAX 10

void print(int arr[MAX]){
    int i = 8;
    for (;i>0;i--,arr++){
        printf("%d ", *arr);
    }
}

int main(void){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    print(arr+2);
    return 0;
}