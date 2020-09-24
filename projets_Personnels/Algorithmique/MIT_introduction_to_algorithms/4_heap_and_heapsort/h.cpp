

void heapify(int arr[], int n, int i){
  int largest = i;
  int l = i*2+1;
  int r  = i*2+2

  if (l < n && arr[l] > arr[largest]){
    largest = l;
  }
  if (r < n && arr[r] > arr[largest]){
    largest = r;
  }
  if (i != largest){
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}


void heapSort(int arr[], int n){
  for (int i(0); i < n/2+1; i++){
    heapify(arr, n, i);
  }
}
