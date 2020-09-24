/*
codeforces.com/contest/344/problem/A
Accepted
*/


#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;


int main(void){
    int n, count = 1;
    cin >> n;
    if (n == 1){
        cout << 1;
        return 0;
    }

    char arr[n];
    for (int i = 0; i < n ; i++){
        string s;
        cin >> s;
        arr[i] = s[1];
    }

    for (int i = 0; i < n-1; i++){
        if (arr[i] != arr[i+1]){
            count++;
        }
    }

    cout << count;
    return 0;
}