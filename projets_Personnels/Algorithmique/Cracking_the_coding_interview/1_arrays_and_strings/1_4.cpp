//Given a string write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

//EXAMPLE  input Tact Coa
//         ouput true (taco cat/ atco cta,...)

/*Thoughts
really don't understand why they work when 'o' !=' '


We could count the number of time we see each character, if they are all even then return true else we use a blank space char to replace any char (?) and if it goes below zero then return false
have to look for hints
*/

//we can't have on a string mutipple char that are odd (only one allowed), the rest must be even


#include <string>
#include <iostream>
#include <iterator>
#include <map>

using std::string;
using std::cout;
using std::endl;

bool perm(string w){
    std::map<char, int> my_map;
    for (string::const_iterator it = w.begin(); it != w.end(); it++){
        if (my_map.count(*it) == 0){
            my_map.insert({*it,1});
        }
        else {
            my_map.at(*it) += 1;
        }
    }
    int nbofuneven = 0;
    for (auto i: my_map){
        //cout << i.first << " " << i.second << endl;
        if (i.second % 2 != 0){
            nbofuneven++;
        }
        if (i.first == ' '){
            nbofuneven--;
        }
    }
    //cout << nbofuneven<< endl;
    if (nbofuneven > 1){
        return false;
    }
return true;
}



int main(int argc, char **argv){
    if (argc != 2){
        cout << "bad number of elem" << endl;
        return 0;
    }
    string w = (string)argv[1];
    cout << perm(w) << endl; 

    return 0;
}
