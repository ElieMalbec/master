#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
  /*Get a word*/
  srand(time(0));
  string word_to_find;
  cout << "Player 1 : choose a word please" << endl;
  cin >> word_to_find;
  string copy_of_word_to_find = word_to_find;

  /*get a random word from the word to find*/

  string word_alea;
  for (int i(0); i < word_to_find.size(); i++){
      int size = copy_of_word_to_find.size();
      int nbAlea = rand() % size;
      word_alea.push_back(copy_of_word_to_find[nbAlea]);
      copy_of_word_to_find.erase(nbAlea,1);
  }

  /*Player 2 try to find the word*/
  cout << "Player 2 : try to discover the word of player 1 !" << endl;
  string word_player2;
  while (true){
    cout << "Trouvez le bon mot : " << word_alea << endl;
    cin >> word_player2;
    if (word_player2 == word_to_find){
      break;
    }
    else{
      cout << "not good" << endl;
    }
  }

  cout << "Well done !" << endl;
  return 0;
}
