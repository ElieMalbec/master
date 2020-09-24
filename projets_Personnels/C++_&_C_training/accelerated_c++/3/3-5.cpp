#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::string;

int main(){
  const double numberOfGrades = 5;
  vector<string> names;
  vector<double> grades;

  cout << "Insert student names :" << endl;
  cout << "First student :" << endl;
  string word;
  while (cin >> word){
    names.push_back(word);

    cout << "Choose the grades of this student" << endl;

    double sum = 0;
    double c = 0;
    double mark;
    while (c < numberOfGrades){
      cin >> mark;
      sum += mark;
      c++;
    }
    grades.push_back(sum / numberOfGrades);

    cout << "Insert another student name :" << endl;
  }

  if (names.size() == 0){
    cout << "You did not insert any names !" << endl;
    return 1;
  }
  else {
    for (int i(0); i < names.size(); i++){
      cout << "Student " << names[i] << " has a final grade of : " << grades[i] << endl;
    }
  }
  return 0;
}
