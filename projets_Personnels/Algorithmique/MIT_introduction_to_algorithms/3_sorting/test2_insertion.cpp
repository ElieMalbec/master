#include <iostream>

using std::cout;
using std::endl;

void insertion(int *arr, int n){
  int j, key;
  for (int i(1); i < n; i++){
    key = arr[i];
    j = i;

    while (j > 0 && arr[j-1] > key){
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = key;
  }
}

void merge(int *arr, int l, int r, int m){

}

void mergeSort(int *arr, int l, int r){
  if ()
  if (l < r){
  int middle = l + (r-l)/2;

  mergeSort(arr, l, middle);
  mergeSort(arr, middle+1, r);
  merge(arr, l, r, middle);
  }
}

int main(){
  int arr[] = {1,5,4,7,9,1,2};
  insertion(arr, 7);
  //cout << sizeof(arr)/sizeof(arr[0]) << endl;

  for (int i(0); i < sizeof(arr)/sizeof(arr[0]); i++){
    cout << arr[i] << endl;
  }
  int arr2[] = {1,5,4,7,9,1,2};
  mergeSort(arr2, 0, 7);
  return 0;
}
