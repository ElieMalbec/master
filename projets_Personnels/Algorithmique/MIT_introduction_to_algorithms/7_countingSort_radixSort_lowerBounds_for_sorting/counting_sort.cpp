#include <iostream>
#define RANGE 10

int ft_max(const int arr[], int size){
  int max = arr[0];
  for (int i(1); i < size; i++){
    if (arr[i] > max) max = arr[i];
  }
  return max;
}

void counting_sort(int arr[], int size){
  //find the max in arr
  int output[size]={0};
  int max = ft_max(arr, size);

  //create count array et initialize everything at zero
  int count[RANGE+1];
  for (int i(0); i <= RANGE; i++){
    count[i] = 0;
  }

  //put number of times there is a number in count
  for (int i(0); i < size; i++){
    count[arr[i]] +=  1;
  }

  //cumulative count
  for (int i(1); i <= RANGE; i++){
    count[i] += count[i-1];
  }

  //get the output value
  for (int i = size - 1; i >= 0; i--) {
      output[count[arr[i]] - 1] = arr[i];
      count[arr[i]]--;
    }
    //copy values of output to arr
  for (int i(0); arr[i]; i++){
    arr[i] = output[i];
  }
}


int main(){
  int arr[] = {1,2,4,5,1,3,4};
  int size = sizeof(arr)/sizeof(arr[0]);

  std::cout << "The array is not sorted : ";
  for (int i(0); i < size; i++){
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
  counting_sort(arr, size);

  std::cout << "The array is sorted : ";
  for (int i(0); i < size; i++){
    std::cout << arr[i] << " " ;
  }
  std::cout << "\n";
  return 0;
}
