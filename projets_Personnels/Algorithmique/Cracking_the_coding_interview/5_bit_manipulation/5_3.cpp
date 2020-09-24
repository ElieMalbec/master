//

/*Thoughts

*/

#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

int flip(int n){
    int temp = n;
    int max = 0;
    int cpt = 0;
    int cpt2 = 0;
    int number = 0;
    for (int i = 1; i < n; i *= 2){
        temp = n & (1 << cpt);
        int count = 0;
        cpt2 = cpt;
        while (n & temp){
            count++;
            if (count > max ) max++;
            cpt2++;
            temp = n & (1 << cpt2);
            if ((temp & n) == 0 && number < 1){
                temp = n | (1 << cpt2);
                number ++;
            }
        }
        cpt++;
        number = 0;
    }
    return max;
}


int main(void){
    
    int n = 1775;

    cout << bitset<32>(n) << endl;
    cout << flip(n) << endl;
    return 0;
}