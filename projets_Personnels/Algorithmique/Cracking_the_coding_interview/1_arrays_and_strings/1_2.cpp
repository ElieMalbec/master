//Given two strings, write a method to decide if one is a permutation of the other

/*thoughts
1 we need to count the number of times every charcomes back in the first word and then check if that's the same on the other string
so we need a dictionnary were the key is the letter and the value the number of times that char is stored
2 or we could begin at the beginning of each string and check if the char  of the first string is found in the second string and then ietrate like that until the end of the first string
*/

//permutation case sensitive ?
//whitespace important ?
//here case sensitive and whitespace immportant

/*
Depending of those rules, if not the same size then can't be good
Sort the string or 
*/

#include <string>
#include <iostream>
#include <map>
#include <iterator>

using std::string;
using std::cout;
using std::endl;
using std::map;


bool perm(const string w1, const string w2){
    if (w1.length() != w2.length()) return false;
    //could have done it with an array
    map<char, int> my_map;
    for (std::string::const_iterator it = w1.begin(); it != w1.end(); it++){
        if (my_map.count(*it) == 0){ //does not exist
            my_map.insert({*it, 1});
        }
        else {
            my_map.at(*it) += 1;
        }
    }

    /* //Printing values of w1 map created
    for(auto it = my_map.cbegin(); it != my_map.cend(); it++)
    {   
        std::cout << it->first << " " << it->second << "\n";
    }
    */
    for (auto it = w2.begin(); it != w2.end(); it++){
        if (my_map.count(*it) == 0) return false;
        else {
            my_map.at(*it) -= 1;
            if (my_map.at(*it) < 0) return false;
        }
    }
    return true;
}

int main(int argc, char **argv){
    if (argc != 3){
        cout << "bad number of elem" << endl;
        return 0;
    }
    string w1 = (string)argv[1];
    string w2(argv[2]);
    cout << w1 << " " << w2 << endl;
    cout << perm(w1,w2) << endl;
    return 0;
}