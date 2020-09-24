//There are three types of edits that can be performed on strings : insert a char remove a char, or replace a char. Given two strings, write a function to check if they are one edit(or zero) away


/*Thoughts
insert : size +1 and check if same char but one more
delete : size -1 and check if same char but one less
modify : same size but one char different(or one more) (need at least two different char)
*/


#include <string>
#include <iostream>
#include <iterator>
#include <map>

using std::string;
using std::cout;
using std::endl;

#define ALPHABET 26

bool OneAway(string w1, string w2){
    int arr[ALPHABET];
    for (int i=0; i < ALPHABET; i++){
        arr[i] = 0;
    }
    /*for (int i=0; i < 26; i++){
        cout << arr[i] << endl;
    }*/
    if (w2.length() == w1.length()){
        for (string::const_iterator it = w1.begin(); it != w1.end(); it++){
            arr[(int)*it -97] += 1;
        }
        for (string::const_iterator it = w2.begin(); it != w2.end(); it++){
            arr[(int)*it -97] -= 1;
        }
        int nbNeg = 0;
        for (int i = 0; i < ALPHABET; i++){
            if (arr[i] < 0){
                nbNeg++;
            }
            if (nbNeg >= 2){
                return false;
            }
        }
        return true;
    }
    if (w2.length() == w1.length() + 1 || w2.length() == w1.length() - 1){//insert & delete
        for (string::const_iterator it = w1.begin(); it != w1.end(); it++){
            arr[(int)*it -97] += 1;
        }
        for (string::const_iterator it = w2.begin(); it != w2.end(); it++){
            arr[(int)*it -97] -= 1;
        }
        for (int i = 0; i < ALPHABET; i++){
            if (arr[i] < 0 ){
                return false;
            }
        }
    }
    else {
        return false;
    }

    return true;
}


int main(int argc, char **argv){
    if (argc != 3){
        cout << "bad number of elem" << endl;
        return 0;
    }
    string w1 = (string)argv[1];
    string w2 = (string)argv[2];
    cout << OneAway(w1,w2) << endl; 

    return 0;
}