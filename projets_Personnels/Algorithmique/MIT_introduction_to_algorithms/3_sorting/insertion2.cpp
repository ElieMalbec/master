


void insertion(int &arr[], int n){
  int j, key;
  for (int i(1); i < n; i++){
    key = arr[i];
    j = i;
    while (j > 0 && key < arr[j-1]){
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = key;
  }

}
