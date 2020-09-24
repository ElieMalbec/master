/*

*/


#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;


int main(void){
    int a,b,c,d;
    string s;
    cin >> a >> b >> c >> d >> s;
    int calories = 0;
    for (int i = 0; i< s.length(); i++){
        if (s[i] == '1'){
            calories+=a;
        }
        if (s[i] == '2'){
            calories+=b;
        }
        if (s[i] == '3'){
            calories+=c;
        }
        if (s[i] == '4'){
            calories+=d;
        }
    }
    cout << calories;
    return 0;
}