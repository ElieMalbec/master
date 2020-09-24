//

/*Thoughts
We could run through the first and second number check them if they both have a 0 or a 1
iF they both have a zero or a one we continue
if the second has a one and the first a zero then we change the value for the first one
*/

#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

int modifyBit2(int number, int position, int bit);
int modifyBit3(int number, int position, int bit);

int modifyBit(int n, int p, int b) 
{ 
    int mask = 1 << p; 
    return (n & ~mask) | ((b << p) & mask); 
} 

int conversion(int n, int m){
    int max = n >= m ? n : m;
    int count = 0;
    int temp = n;
    int nbChanges = 0;
    for (int i = 1; i < max; i *= 2){
        //if m has a 1 and n has a 0
        if (((m & (1 << count)) != 0) && ((n & (1 << count)) == 0)){
            temp = modifyBit3(temp, count, 1);
            nbChanges++;
        }
        //if m has a 0 and n has a 1
        else if (((m & (1 << count)) == 0) && ((n & (1 << count)) != 0)){
            temp = modifyBit2(temp, count, 0);
            nbChanges++;
        }
        count++;
    }
    cout << bitset<32>(n) << endl;
    cout << bitset<32>(temp) << endl;
    cout << bitset<32>(m) << endl;
    return nbChanges;
}

//put them at zero
int modifyBit2(int number, int position, int bit){ 
    int mask = 1 << position;
    return (number & ~mask);
}

//put them at one
int modifyBit3(int number, int position, int bit){
    int mask = 1 << position;
    return (number & ~mask) | mask;
}

int main(void){
    
    int n = 29;
    int m = 15;

    cout << "Test : " << bitset<32>(n) << endl;
    cout << "Test : " << bitset<32>(1 << 2) << endl;
    cout << "Test : " << bitset<32>(~(1 << 2)) << endl;
    cout << "Test : " << bitset<32>(n & (~(1 << 2))) << endl;
    //cout << (1 << 3)<< endl;
    //cout << bitset<32>((1 << 3)) << endl;

    cout << conversion(n, m) << endl;
    //cout << flip(n) << endl;
    return 0;
}