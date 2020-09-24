#include <iostream>
#include <string>
#include <string.h>


using std::string;
using std::cout;
using std::endl;
int len(char * str){
    int i = 0;
    for (i; str[i] != '\0'; i++){

    }
    return i;
}
void print(string str){
    for (int i = 0; i < str.length(); i++){
        cout << str[i];
    }
    cout << endl;
}
void print(char * str2){
    for (int i = 0; i < len(str2); i++){
        cout << str2[i];
    }
    cout << endl;
}

int main(void){
    string str = "HELlo";
    char * str2 = new char [strlen("HELlo") + 1];
    strcpy(str2, "HELlo");

    cout << "str "; print(str);
    cout << "str2 ";print(str2);
    cout << "###################" << endl;
    for (int i = 0; i < str.length(); i++){
        str[i]= tolower(str[i]);
    }
    for (int i = 0; i < len(str2); i++){
        str[i]= toupper(str2[i]);
    }
    cout << "str ";print(str);
    cout << "str2 ";print(str2);
    return 0;
}