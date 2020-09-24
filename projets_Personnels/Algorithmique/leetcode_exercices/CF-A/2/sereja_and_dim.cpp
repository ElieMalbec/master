/*
http://codeforces.com/contest/381/problem/A
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
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int last = n -1;
    int debut = 0;

    int sereja = 0;
    int dima = 0;

    while (debut <= last){
        if (arr[debut] >= arr[last]){
            sereja += arr[debut];
            debut++;
        }
        else {
            sereja += arr[last];
            last--;
        }
        if (debut > last || last < debut) break;
        if (arr[debut] >= arr[last]){
            dima += arr[debut];
            debut++;
        }
        else {
            dima += arr[last];
            last--;
        }
    }

    cout << sereja << " " << dima;
    return 0;
}