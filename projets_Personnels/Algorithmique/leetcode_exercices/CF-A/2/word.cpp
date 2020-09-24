/*
codeforces.com/contest/59/problem/A
Accepted
*/


#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;


void lowerMe(string &s){
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] > 64  && s[i] < 91){
            s[i] += 32;
        }
    }
}

void upperMe(string &s){
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] > 96  && s[i] < 123){
            s[i] -= 32;
        }
    }
}

int main(void){
    string s;

    cin >> s;
    int lower = 0;
    int upper = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] > 96  && s[i] < 123){
            lower++;
        }
        if (s[i] > 64  && s[i] < 91){
            upper++;
        }
    }
    if (lower >= upper){
        lowerMe(s);
    }
    else {
        upperMe(s);
    }
    cout << s;
    return 0;
}