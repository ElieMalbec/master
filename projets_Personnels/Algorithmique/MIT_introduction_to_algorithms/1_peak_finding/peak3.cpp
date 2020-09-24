

int peak(int arr[], int l, int r){
  int m = l + (r-l)/2;
  if (arr[m] >= arr[m+1] && arr[m] >= arr[m-1]){
    return m;
  }
  else if (arr[m] < arr[m+1]){
    peak(arr, m+1, r);
  }
  else {
    peak(arr, l, m);
  }
}
