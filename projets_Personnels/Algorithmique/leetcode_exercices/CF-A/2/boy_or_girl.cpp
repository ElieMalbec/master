/*
codeforces.com/contest/236/problem/A
Accepted
*/

#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::map;


int main(void){
    string s;
    cin >> s;

    map<char, int> my_map;
    for (int i = 0; s[i] != '\0'; i++){
        if (my_map.find(s[i]) != my_map.end()){
            continue;
        }
        else {
            my_map.insert({s[i], 1});
        }
    }

    if (my_map.size() % 2 == 0) cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";


    return 0;
}