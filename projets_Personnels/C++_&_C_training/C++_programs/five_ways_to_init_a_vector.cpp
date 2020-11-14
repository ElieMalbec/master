#include <iostream>
#include <vector>

using std::vector;

int main(void){
  vector<int> h(2,3);//specifies an n number of times the same values (value, n)

  vector<int> v{1,2,3};
  vector<int> h2(v.begin(), v.end());

  vector<int> h3; //with push_back
  h3.push_back(20);

  vector<int> h4{1,2,5};//llike an array

  int arr[] = {1,2,3};//from an array
  vector<int> h5(arr, arr + (sizeof(arr)/sizeof(arr[0])));
  return 0;
}
