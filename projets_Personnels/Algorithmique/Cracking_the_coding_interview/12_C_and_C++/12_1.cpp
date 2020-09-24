//

/*Thoughts
We could count the number of lines and if the K last lines exist we just print them. We first need to check if the file is empty or not.
We could use a pointer on the first line and then move it one by one when we have at least K lines read. 
*/

//use circular array

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::vector;

/*
bool is_empty(fstream& my_file)
{
    return my_file.peek() == fstream::traits_type::eof();
}

void    lastKLines(fstream &my_file, int k){
    if (!(is_empty(my_file))) return;

    vector<string> rememberKLines[k];
    int count = 0;


}
*/

int main(void){
    fstream my_file;
    my_file.open("hello.txt");
    lastKLines(my_file, 5);
    return 0;
}