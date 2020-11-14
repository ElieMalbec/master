#include <iostream>
#include <fstream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::fstream;
using std::map;


//array
//dequeue
//forward_list
    //difference forward_list and list ?
//list
//map
//queue
//priority_queue
//set
//stack

//pointers vs references
//C++ Namespaces

map<string, string> m = {
    {"How to delete one part of a string ?", "use str.erase(position, len)"},
    {"How to create a substring of a string ?", "use str.substr(position, len)"},
    {"How to reverse a string ?", "use reverse(str.begin(), str.end())"},
    {"How to copy a string ?", "use str.copy(dest string, len, position)"},
    {"How to get a C string equivalent (char *)?", "use str.c_str()"},
    {"How to change a int/double into a string ?", "use to_string(value)"},
    {"How to check if a string is empty ?", "use str.empty()"},
    {"How to get the size of a string ?", "use str.size() or str.length()"},
    {"How to find a character/string in a string ?", "use str.find(char/str, position)"},
    {"How to swap two strings ?", "use str.swap(str2)"},
    {"How to get a reference to the first character in a string ?", "use str.front()"},
    {"How to insert a string (or part of it) into a string ?", "use str.insert(position, str2)"},
    {"How to delete the last character in a string ?", "use str.pop_back()"},
    {"How to append a character at the end of a string ?", "use str.push_back(char)"},
    {"How to replace one part of a string with another string ?", "use str.replace(position, len, str2)"},
    {"How to append multiples character (or a string) at the end of a string ?", "use str += \"string\"  or use str.append(str2)"},



    {"How to look for a key in a vector ?", "if (std::find(v.begin(), v.end(), value) != v.end())"},
    {"What does std::vector::at do ?", "Returns an iterator to the element at position n in the vector"},
    {"How to get a reference to the last element of the vector ?", "use v.back()"},
    {"How to get a iterator to the first element of the vector ?", "use v.begin()"},
    {"How to clear a vector of all it's elements ?", "use v.clear()"},
    {"How to check if a vector is empty ?", "use v.empty()"},
    {"What does std::vector::end() do ?", "Returns a reference to the past-the-end element in the vector"},
    {"How to erase a value in a vector ?", "use v.erase(position) / (between low and high) v.erase(low, high)"},
    {"How to get a reference to the first element of the vector ?", "use v.front()"},
    {"How to remove an element from the back of a vector ?", "use v.pop_back()"},
    {"How to add an element from the back of a vector ?", "use v.push_back(value)"},
    {"How to get the size of a vector ?", "use v.size()"},
    {"How to insert an element at a given position in a vector ?", "use v.insert(iterator position, value)"},

    {"what stack::emplace(value), stack::empty(), stack::pop(), stack::push(value), stack::size(), stack::top() do?", "add at the top, check if empty, pop the top element, push the value to the top of the stack, get the number of elements of the stack, return a reference to the top element of the stack"},
    {"How does cbegin(), cend, rbegin(), rend() return ?", "cons_iterator to the first/past-the-end element, same but for the reverse element"},

    {"How to transform an hex string into a int decimal ?", "std::stoul(my_string, nullptr, 16)"}
};

int main(void){
    cout << "##### WELCOME TO REVIEW YOUR KNOWLEDGE ON C++ #####" << endl;
    cout << "Please use an int when the console ask for input"<< endl << endl;
    int n;

    //
    for (auto it = m.begin();it != m.end(); it++){
        cout << it->first << endl;
        cin >> n; cout << '\r';
        cout << "--> " << it->second << endl;
        cout << "############################################" << endl;
    }
    //cout << "How to delete one part of a string ?"

    return 0;
}


