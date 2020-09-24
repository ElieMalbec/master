/*
http://codeforces.com/contest/427/problem/A

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

    int event[n];
    for (int i = 0; i < n; i++){
        cin >> event[i];
    }

    int crime = 0;
    int policeOfficer = 0;

    for (int i = 0; i < n; i++){
        if (event[i] == -1 && policeOfficer == 0){
            crime++;
        }
        else if (event[i] == -1 && policeOfficer > 0){
            policeOfficer--;
        }
        else if (event[i] >= 10 || (event[i] > 0 && policeOfficer + event[i] > 10)){
            policeOfficer = 10;
        }
        else if (event[i] > 0 && policeOfficer + event[i] < 10){
            policeOfficer += event[i];
        }
    }
    cout << crime;
    return 0;
}