#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void affiche(vector<int> arr);
void insertion(vector<int> &arr);

int main(){
  vector<int> arr{1,8,5,3,4,9,7};
  affiche(arr);
  insertion(arr);
  cout << "Now sorted" << endl;
  affiche(arr);

  cout << "Merge sort" << endl;
  vector<int> arr2{1,8,5,3,4,9,7};
  affiche(arr2);
  mergeSort(arr2, 0, arr2.size()-1);
  affiche(arr2);

  return 0;
}

void affiche(vector<int> arr){
  for (int i(0); i < arr.size(); i++){
    cout << arr[i];
  }
}

void insertion(vector<int> &arr){
  int j;
  for (int i(1); i < arr.size(); i++){
    j = i;
    while (arr[i] < arr[i-1] && j > 0){
      int temp = arr[i];
      arr[i] = arr[i-1];
      arr[i-1] = temp;
      i-=1;
    }
  }
}

void mergeSort(vector<int> &arr, int l, int r){
  if (l < r){
    int m = l + (r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
  }
}

void merge(vector<int> &arr, int l, int r, int m){
  
}
