#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ios>

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;
using std::istream;

istream& read(istream& in, vector<string>& word);
int uniqueWords(const vector<string>& words);


int main(){
  vector<string> words;
  read(cin, words);
  cout << "words contains " << words.size() << " elements." << endl;
  cout << "There is " << uniqueWords(words) << "unique words." << endl;
  return 0;
}

istream& read(istream& in, vector<string>& word){
  string w;
  while (in >> w){
    word.push_back(w);
  }

  in.clear();
  return in;
}

int uniqueWords(const vector<string>& words){
  vector<string> w;
  for (int i(0); i < words.size(); i++){
    if (!(std::find(w.begin(), w.end(), words[i]))){
      w.push_back(words[i]);
    }
  }
  return w.size();
}
