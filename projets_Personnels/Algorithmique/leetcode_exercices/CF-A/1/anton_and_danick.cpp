/*
https://codeforces.com/contest/734/problem/A
Accepted
*/

#include<iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(void){
    int n;
    int A = 0;
    int D = 0;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++){
        if (s[i] == 'A'){
            A++;
        }
        else {
            D++;
        }
    }
    if (A == D) cout << "Friendship";
    else {
        cout << (A > D ? "Anton" : "Danik");
    }
    return 0;
}