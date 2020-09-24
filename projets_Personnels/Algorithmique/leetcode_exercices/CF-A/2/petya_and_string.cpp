/*
http://codeforces.com/contest/112/problem/A
Accepted
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;


int main(void){
    string s1,s2;
    cin >> s1 >> s2;

    for (int i = 0; s1[i] != '\0' ; i++){
        if (s1[i] > 96){
            s1[i] -= 32;
        }
        if (s2[i] > 96){
            s2[i] -= 32;
        }
        if (s1[i] == s2[i]){
            continue;
        }
        else {
            cout << (s1[i] < s2[i] ? -1 : 1);
            return 0;
        }
    }
    cout << 0;
    return 0;
}