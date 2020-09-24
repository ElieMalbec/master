//

/*Thoughts
For this exercice we can multiply by two the number, if it goes over 1 then we print 1 and remove 1, if it's below one then we print 0 and continue and if it it exactly 1 then we print 1 and we are done
*/

#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

void binToString(double n){
    cout << "0.";
    for (int i = 0; i < 32; i++)
    {
        n *= 2;
        if (n > 1){
            cout << "1";
            n -= 1;
        }
        else if (n < 1){
            cout << "0";
        }
        else if (n == 1){
            cout << "1";
            return;
        }
    }
    cout << endl << "Error, not enough accurate";
}


int main(void){
    
    double n = 0.25;

    //cout << bitset<32>(n) << endl;
    binToString(n);
    cout << endl;
    return 0;
}