#include <iostream>


void printMe(int **arr, int row, int col){
  for (int i(0); i < row; i++){
    for (int j(0); j < col; j++){
      std::cout << arr[i][j] << std::endl;
    }
  }
}

int main(){
  int arr[][3]={{1,2,3},{4,5,6}};
  //int (*ptr)[3]=&arr;
  printMe(ptr,2,3);
/*
  int arr[2][5] =
      {
          {1,8,12,20,25},
          {5,9,13,24,26}
      };
*/

//declare a pointer to muldi array
/*
  const int someheight = 2;
  const int somewidth = 3;

  int (*array)[somewidth] = new int[someheight][somewidth];
*/

/*Deallocate
  for (int count = 0; count < 10; ++count)
      delete[] array[count];
  delete[] array; // this needs to be done last
*/

/****************************
int a = 10;
  int *p = &a;
         OR
     int *p;
   p = &a;
we can declare and initialize pointer at same step or in multiple line.

int a=10;
int &p=a;  //it is correct
   but
int &p;
 p=a;    // it is incorrect as we should declare and initialize references at single step.


******************************/
}
