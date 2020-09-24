/*
http://codeforces.com/contest/405/problem/A
Accepted
*/

#define ROWS 5
#define COLS 5

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

int main(void){
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //sorting
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }

    //printing the array
    for (int i = 0; i < n; i++){
        if (i == n-1) cout << arr[i];
        else cout << arr[i] << " ";
    }
    return 0;
}