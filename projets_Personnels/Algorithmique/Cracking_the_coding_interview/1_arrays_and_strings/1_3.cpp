//write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string
//examples :    input "Mr John Smith", 13
//              output"Mr%20John%20Smith"

/*Thoughts
We could check the number of space in our input and then allocate an array with the right amount of space necessary and then copy the input with %20 in blank spaces
to calculate the right number for our space we can see that a space takes 1 char but we change it by three. So result is : totalLen - numberOfSpaces + numberOfSpaces*3
I would ask if it's just regular spaces or like on the c function isspace()
*/

#include <string>
#include <iostream>
#include <iterator>
#include <cstring>

using std::string;
using std::cout;
using std::endl;

int space(string w){
    int n = 0;
    for (std::string::const_iterator it = w.begin(); it != w.end(); it++){
        if (*it == ' ') n++;
    }
    return n;
}

string URLify(string w){
    int nmberSpaces = space(w);//if we do like this and use a char [] instead of a string we would malloc it with the size n
    string str_modify;
    if (nmberSpaces == 0) return w; 
    for (std::string::const_iterator it = w.begin(); it != w.end(); it++){
        if (*it == ' '){
            str_modify.push_back('%');
            str_modify.push_back('2');
            str_modify.push_back('0');
        }
        else {
            str_modify.push_back(*it);
        }
    }
    return str_modify;
}

int main(int argc, char **argv){
    if (argc != 3){
        cout << "bad number of elem" << endl;
        return 0;
    }
    string w1 = (string)argv[1];
    int my_len(atoi(argv[2]));

    cout << URLify(w1) << endl;

    return 0;
}