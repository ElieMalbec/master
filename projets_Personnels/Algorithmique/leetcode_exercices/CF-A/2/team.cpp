/*
https://codeforces.com/contest/231/problem/A
Accepted
*/

#define FRIENDS 3

#include<iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(void){
    int nbproblems, count = 0;
    cin >> nbproblems;

    for (int i = 0; i < nbproblems; i++){
        int temp = 0;
        for (int j = 0; j < FRIENDS; j++){
            int t;
            cin >> t;
            temp+= t;
        }
        if (temp >= 2) count++;
    }
    cout << count;
    return 0;
}