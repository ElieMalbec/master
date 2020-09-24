#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
/**
  * Check if it's a palindrome
**/
int main(){
  string words[] = {"Hello", "friend", "kayak", "caac", "cac"};
  int size = sizeof(words)/sizeof(words[0]);
  //cout << size << endl;
  for (int i(0);i < size; i++){
    int sizeWord = words[i].length();
    //cout << sizeWord << endl;
    int len = sizeWord-1;
    int j = 0;
    while (words[i][j] == words[i][len] && j < sizeWord/2){
      j++;len--;
      if (words[i][j] == words[i][len] && j == sizeWord/2){
        cout << "is palindrome : " << words[i] << endl;
      }
      else {
        continue;
      }
    }
  }
  return 0;
}
