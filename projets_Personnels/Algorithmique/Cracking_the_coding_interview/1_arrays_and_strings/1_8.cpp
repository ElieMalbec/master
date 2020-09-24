//Write an algorithm such that if an element in a MxN matrix is 0, it's entire row and column are set to 0.

/*Thoughts
i believe if you check one time and that there is a zero then not all the matrix becomes full of zero
So we need to store which row and colum will be set to zero while iterating through the MxN matrix.
so we could store it on 2 array of size M and N, one for the rows and the other for columns.
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

#define M 3
#define N 4

void rowToZero(int (&arr)[M][N], int nbRow){
    for (int i = 0; i < N; i++)
    {
        arr[nbRow][i] = 0;
    }
}

void colToZero(int (&arr)[M][N], int nbCol){
    for (int i = 0; i < M; i++)
    {
        arr[i][nbCol] = 0;
    }
}

void zeroMatrix(int (&arr)[M][N]){
    vector<int> row;
    vector<int> col;   
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if (arr[i][j] == 0){
                if (!(std::count(row.begin(), row.end(), i))){
                    row.push_back(i);
                }
                if (!(std::count(col.begin(), col.end(), j))){
                    col.push_back(j);
                }
            }
        }
    }
    /* //printing row & col
    for (vector<int>::const_iterator i = row.begin(); i != row.end(); ++i){
        cout << *i << ' ';
    }
    for (vector<int>::const_iterator i = col.begin(); i != col.end(); ++i){
        cout << *i << ' ';
    }
    cout << endl;
    */
    for (vector<int>::const_iterator i = row.begin(); i != row.end(); ++i){
        rowToZero(arr, *i);
    }
    for (vector<int>::const_iterator i = col.begin(); i != col.end(); ++i){
        colToZero(arr, *i);
    }
}

int main(void){
    int arr[M][N]= {0,1,2,3,4,0,6,7,8,9,10,11};
    zeroMatrix(arr);

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}