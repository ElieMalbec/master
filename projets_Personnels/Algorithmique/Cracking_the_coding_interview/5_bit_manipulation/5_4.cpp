//

/*Thoughts
You need to move the rightmost 1 to the left (where there is a 0) to have the biggest next int
You need to move the leftmost 1 to the right (where there is a 0) to have the smallest next int
*/

#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

/*
void next(int n){
    int temp = n;
    int count = 0;
    //smallest first
    for (int i = 1; i < n; i *= 2){
        int count2 = count2 + count;
        while ((temp  & (1 << count2)) == 0){
            count2++;
            if ((temp  & (1 << (count2 + 1))) != 0){
                temp = temp | (1 << (count2));
                //temp = temp & (1 << (count2 + 1));
                //temp = temp | n;
                break;
            }
        }

        count++;
    }
    cout << temp << endl;
    cout << bitset<32>(temp) << endl;
}*/

int main(void){
    
    int n = 52;
    cout << n << endl;
    cout << bitset<32>(n) << endl;

    //cout << bitset<32>(n) << endl;
    next(n);
    return 0;
}