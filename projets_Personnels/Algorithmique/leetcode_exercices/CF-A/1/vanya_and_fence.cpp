/*
https://codeforces.com/contest/677/problem/A
ACCEPTED
*/

#include<iostream>


#define MAX 1000
using std::cout;
using std::endl;
using std::cin;

int vanya(int*, int*);

int vanya(int *arr, int *values){
    int weight = 0;
    int height = arr[1];

    for (int i = 0; i < arr[0]; i++){
        if (values[i] > height){
            weight+=2;
        }
        else {
            weight+=1;
        }
    }
    return weight;
}

int main(void){

    int arr[2];
    cin >> arr[0];
    cin >> arr[1];
    int values[MAX];
   
    for (int i = 0; i < arr[0]; i++){
        cin >> values[i];
    }

    cout << vanya(arr, values) << endl;
    return 0;
}