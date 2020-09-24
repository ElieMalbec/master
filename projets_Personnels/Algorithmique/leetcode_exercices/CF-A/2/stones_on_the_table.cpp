/*
http://codeforces.com/contest/266/problem/A
Accepted
*/


#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;


int main(void){
    int n;
    cin >> n;

    char arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++){
        if (arr[i] == arr[i+1]){
            count++;
        }
    }
    
    cout << count;
    return 0;
}