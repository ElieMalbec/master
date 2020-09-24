//not working
#include <iostream>
#include "peak.h"

int divide(int arr[], int debut, int fin);
int main(void){
  std::cout << "Our job is to find a peak (b>= a & b>=c) in a 1D array" << std::endl;
  std::cout << "The straight forward algorithm" << std::endl;
  int arr[7]= { 5, 4, 8, 12, 14, 13, 1};

  int max = 0;
  int pos = 0;
  for (int i(0); i < (sizeof(arr) / sizeof(arr[0])); i++){
    if (arr[i] > max){
      max = arr[i];
      pos = i;
    }
  }
  std::cout << "The peak is " << max << " at position " << pos << std::endl;
  std::cout << "His complexity is theta (n)" << std::endl << std::endl;
  std::cout << "The divide and conquer algorithm" << std::endl;
  int peak = divide(&arr, 0, (sizeof(arr) / sizeof(arr[0])));

}


int divide(int arr[], int debut, int fin){
  int middle = debut + (debut - fin) / 2;
  if (arr[middle] < arr[middle-1]){
    fin = middle;
    divide(arr, debut, fin);
  }
  else if (arr[middle] < arr[middle+1]){
    debut = middle;
    divide(arr, debut, fin);
  }
  else {
    return arr[middle];
  }
}
