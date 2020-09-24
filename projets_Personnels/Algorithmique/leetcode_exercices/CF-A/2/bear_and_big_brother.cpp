/*
https://codeforces.com/contest/791/problem/A
Accepted
*/

#include<iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(void){
    int a, b, count = 0;
    cin >> a >> b;
    while (a <= b){
        a*=3;
        b*=2;
        count++;
    }
    cout << count;
    return 0;
}