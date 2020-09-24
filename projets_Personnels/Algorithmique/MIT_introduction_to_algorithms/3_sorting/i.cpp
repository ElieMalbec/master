#include <iostream>

void insertion(int *arr, int n){
  int key, j;
  for (int i(1); i < n; i++){
    key = arr[i];
    j = i;
    while (key < arr[j-1] && j > 0){
      arr[j] = arr[j-1];
      j--;
    }
    arr[j]  =key;
  }
}

int main() {
  int arr[] = {1,5,4,3,2};
  insertion(arr, 5);
  return 0;
}
