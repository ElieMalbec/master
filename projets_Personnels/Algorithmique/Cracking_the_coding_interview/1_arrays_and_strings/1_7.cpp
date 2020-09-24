//Given an image represented by NxN matrix, wehre each pixel i the image is 4 bytes, write a method to rotate the image y 90degree. Can you do this in place ?


/*Thougts
i will suppose that the pixels are int and it's a nxn matrix of int
do first line, last colum, last line, first column. first the corner, then between the corner.
Then do the same with the line and column inside

I don't know
*/

#define N 4


#include <string>
#include <iostream>
#include <iterator>


using std::string;
using std::cout;
using std::endl;

void changeCorner(int (&arr)[N][N]){
    int temp = arr[0][N];
    int temp2 = arr[N][N];
    int temp3 = arr[N][0];
    int temp4 = arr[0][0];

    arr[0][N] = temp4;
    arr[N][N] = temp;
    arr[N][0] = temp2;
    arr[0][0] = temp3;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

void rotate(int (&arr)[N][N]){
    int loop = N/2;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
    changeCorner(arr);
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}




int main(void){
    int arr[N][N]= {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
    rotate(arr);
    //cout << arr << endl; 

    return 0;
}
