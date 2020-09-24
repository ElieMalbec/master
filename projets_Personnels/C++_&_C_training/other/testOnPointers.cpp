#include <iostream>

int main(){
  int const ROW = 5;
  int const COL = 6;
	int **arr = new int* [ROW];

	for (int i = 0; i < ROW; i++){
		arr[i] = new int [COL];
	}
  //insert values
	for (int i = 0; i < ROW; i++){
		for (int j = 0 ; j < COL; j++){
			arr[i][j] = i;
		}
	}
  //print values
	for (int i = 0; i < ROW; i++){
		for (int j = 0 ; j < COL; j++){
			std::cout << arr[i][j] << " ";
		}
	}

	std::cout << std::endl;

	int const SIZE = 15;
	arr[2] = new int [SIZE];
	for (int i = 0; i < 10; i++){
		arr[2][i] = 9;
	}
	for (int i = 0; i < SIZE; i++){
			printf("%d ", arr[2][i]);
	}

/*
  std::vector <int> v{1,2,3};
  std::vector<int> v(n,number);
  std::vector<int> v1{1,2,3};
  std::vector<int> v2(v1.begin(), v1.end());
  int arr[] = {1,2,3};
  std::vector<int> v(arr, arr + (sizeof(arr)/sizeof(arr[0])));
*/
	return 0;
}
