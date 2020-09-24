//

/*Thoughts
First we need to clear all the bits of N between i and j to zero and then insert M at the right position.
To clear we can do all ones and then all zero at the right position and then all ones.
*/

#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;


int insertion(int n, int m, int i, int j){
    int ones = ~0;
    int left = ones << (j+1);
    //cout << bitset<32>(left) << endl;
    int right = ((1 << i) - 1);
    //cout << bitset<32>(right) << endl;

    int mask = left | right;
    cout << bitset<32>(mask) << endl;

    n = n & mask;
    cout << bitset<32>(n) << endl;

    m = m << i;

    n = n | m;

    return n;
}

int main(void){
    
    int N = 465;
    int M = 19;
    int I = 2;
    int J = 6;

    cout << bitset<32>(N) << endl;
    cout << bitset<32>(M) << endl;
    

    cout << bitset<32>(insertion(N, M, I, J)) << endl;
    
    return 0;
}