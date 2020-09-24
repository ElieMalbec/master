//implement an algorithm to determine if a string has all unique characters. What if you cannot use additionnal data structures ?

/* thoughts
1 What we could do is to iterate through the string and at every character we iterate from the beginning to that character to check if it already exists. Bad running time n^n
2 We could also use a dictionnary to store every characters and check if it is already in it.
*/

//You could also sort the array and check neighbours
//Need check if over space limit number of char

//ASCII char, using an array of bool
#include <iostream>
#include <string>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int NUMBER_ELEM = 128;
bool everyChar[NUMBER_ELEM];

bool has_unique(const string word){
    if (word.length() > 128) return false;

    for (string::const_iterator it = word.begin(); it != word.end(); it++){
        int n = (int) *it;
        if (everyChar[n] == true) return false;
        else {
            everyChar[n] = true;
        }
    }
    return true;
}

int main(void){
    for (int i = 0; i < NUMBER_ELEM; i++){
        everyChar[i] = false;
    }
    cout << "Write a string" << endl;
    string word;
    cin >> word;
    cout << "The string has unique (0 false, 1 true) : " << has_unique(word) << endl;
    return 0;
}