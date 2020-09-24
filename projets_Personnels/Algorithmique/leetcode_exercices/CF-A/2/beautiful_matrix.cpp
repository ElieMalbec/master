/*
http://codeforces.com/contest/263/problem/A
Accepted
*/

#define ROWS 5
#define COLS 5

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

struct Position{
    int x;
    int y;

    Position(int x, int y){
        this->x = x;
        this->y = y;
    }
};

Position *locateOne(int arr[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            if (arr[i][j] == 1){
                Position *newPos = new Position(i, j);
                return newPos;
            }
        }
    }
}

int main(void){
    int arr[ROWS][COLS];
    int xBeautiful = 2;
    int yBeautiful = 2;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            cin >> arr[i][j];
        }
    }
    Position *one = locateOne(arr);

    int count = 0;
    while (one->x != xBeautiful){
        if (one->x < xBeautiful){
            one->x++;
            count++;
        }
        else {
            one->x--;
            count++;
        }
    }

    while (one->y != yBeautiful){
        if (one->y < yBeautiful){
            one->y++;
            count++;
        }
        else {
            one->y--;
            count++;
        }
    }

    cout << count;
    return 0;
}