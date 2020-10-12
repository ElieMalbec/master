// Write a program to get a user input as Integer variable using
// “scanf”. Convert the integer into character string and print the
// same as string using “printf”. Do not use any library functions
// except scanf & printf.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 51

void reverse(char arr[], int start, int end);

int main(void){
    char a[MAX];
    char b[MAX];
    int   d[MAX];
    for (int i = 0; i < MAX; i++){
        a[i] = '\0';
    }
    for (int i = 0; i < MAX; i++){
        d[i] = 0;
    }

    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", d);
    //print a
    for (int i = 0; i < MAX && a[i] != '\0'; i++){
        printf("%d \n", a[i] - '0');
    }
    printf("\n");
    //print b
    for (int i = 0; i < MAX && b[i] != '\0'; i++){
        printf("%d \n", b[i] - '0');
    }
    printf("\n");
    for (int i = 0; i < MAX; i++){
        printf("%d ", d[i]);
    }
    printf("\n");

    for (int i = 0; i < MAX && (a[i] != '\0' || b[i] != '\0'); i++){
        printf("%d ", (a[i]-'0') + (b[i]-'0') );
    }
    printf("\n");
    //go from the first
    //
    reverse(a, 0, MAX-1);
    reverse(b, 0, MAX-1);
    //print a
    for (int i = 0; i < MAX; i++){
        printf("%d ", a[i] - '0');
    }
    //print b
    for (int i = 0; i < MAX ; i++){
        printf("%d ", b[i] - '0');
    }
    char c[MAX];
    return 0;
}

void reverse(char arr[], int start, int end)
{
    char temp;
    while (start < end)
    {
        temp = arr[start];   
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }   
} 
