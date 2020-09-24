//

/*Thoughts

*/

#include <iostream>

using std::cout;
using std::endl;



void print(int *arr, int len){
    for (int i = 0; i <  len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortedMerge(int a[10], int b[]){
    if (b == nullptr) return;
    int temp = (a[0] < b[0]) ? a[0] : b[0];

    int i = 0; int j = 0;
    while (j  < sizeof(b)/sizeof(b[0])){
        
    }
}


/*
int * sortedMerge(int *A, int *B){
    if (A == nullptr && B == nullptr) return nullptr;
    if (A && B == nullptr) return A;
    if (A == nullptr && B) return B;

    int *C = new int [sizeof(A)/sizeof(A[0])];
    int i = 0; int j = 0; int k = 0;
    while (i < sizeof(A)/sizeof(A[0]) | j < sizeof(B)/sizeof(B[0])){
        if (A[i] < B[j]){
                        C[i+j] = A[i];

            i++;
        }
        else if (A[i] >= B[j]){
            C[i+j] = B[j];
            j++;
        }
    }

    if (A[i]){
        for (i; i < sizeof(A)/sizeof(A[0]); i++){
            if (C[i+j]){
                C[i+j] = A[i];
            }
        }
    }
    /*else if (B[j]){
        for (j; j < sizeof(B)/sizeof(B[0]); j++){
            if (C[i+j]){
                C[i+j] = B[j];
            }
        }
    }*//*
    return C;
}*/

int main(void){
    int A[10] = {1,5,6,9};
    int B[] = {4,7,12};
    cout << sizeof(A)/sizeof(A[0]) << endl;
    print(A,10);
    print(B,3);
    //int *C = sortedMerge(A,B);
    sortedMerge(A, B);
    print(A,10);
    print(B,3);
    //print(C,10);
    return 0;
}