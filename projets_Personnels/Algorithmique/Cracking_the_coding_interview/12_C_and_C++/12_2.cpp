//

/*Thoughts
We go to the end of the file with a pointer
we have another pointer on the beginning
and then iterate array.length()/2 on it and swap each value (decrease our end pointer by one each time)

We could create a linked list that hold every char and pushing them everytime on the front. And them retrieve them.
doesnot look more efficient
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::vector;

void reverse_str(char *str){
    char *end = str;
    char *beg = str;
    char temp;

    if (str){
        while (*end){
            end++;
        }
    }
    else {
        return;
    }

    end--;
    while (beg < end){
        temp = *beg;
        *beg = *end;
        *end = temp;
        beg++; end--;
    }
}

void print(char *str){
    for (int i = 0; str[i] != '\0'; i++){
        cout << str[i];
    }
    cout << endl;
}

int main(void){
    char  str[] = "Hello friend";
    char * t = str;
    print(t);
    reverse_str(t);
    print(t);
    return 0;
}