//Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring
//EXAMPLE waterbottle is a rotation of erbottlewat

/* Thoughts
If we have isSubstring we need to check twice if it's a substring
wat........ && ........wat
...erbottle & erbottle... BUT WE HAVE TO CALL OF isSubstring

Or we could sort the arrays and then check if it is a substring

Or we could try to recreate the original string: if there is the char w1 in w2 then we delete it in w2 (but we have to do multiple searh in the array)
*/

//we concatenate w1 with w1 and then call isSubstring
#include <iostream>
#include <iterator>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool strRotation(string w1, string w2){
    int len = w1.length();
    if (len == w2.length() && len > 0){
        string w1w1 = w1 + w1;
        return isSubstring(w1w1, w2);
    }
    return false;
}

int main(void){
    string w1 = "waterbottle";
    string w2 = "erbottlewat";
    cout << strRotation(w1,w2)<< endl;

    return 0;
}