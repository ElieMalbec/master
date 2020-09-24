//Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the compressed string would not become smaller than the orginal string, your method should return the original string. You can assume the string has only uppercase and lowercase letters

/*THOUGHTS
i suppose it is case sensitive
so everytime we found a char we need another counter who will check how many of that character there is
*/


#include <string>
#include <iostream>
#include <iterator>
#include <map>

using std::string;
using std::cout;
using std::endl;

string strCompression(string w){
    string w2;
    for (int i = 0; i < w.length(); i++){
        int j = 0;
        int cpt = 0;
        while (w[i+j] != '\0' && w[i] == w[i+j]){
            cpt++;
            j++;
        }
        w2.push_back(w[i]);
        w2.push_back((char)cpt+48);
        i+=cpt-1;
    }
    //cout << w2 << endl;
    if (w2.length() >= w.length()){
        return w;
    }
    return w2;
}


int main(int argc, char **argv){
    if (argc != 2){
        cout << "bad number of elem" << endl;
        return 0;
    }
    string w1 = (string)argv[1];
    cout << strCompression(w1) << endl; 

    return 0;
}