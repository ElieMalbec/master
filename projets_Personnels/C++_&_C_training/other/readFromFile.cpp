#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::istringstream;

int main(){
  //creating and opening a file (checking for errors)
  ifstream studentFile;
  studentFile.open("./students.txt");
  if (studentFile.is_open()){
    cout << "File well opened :)" << endl << endl;
  }
  else {
    cout << "Error opening the file" <<  endl;
    return -1;
  }

  //counting number of lines
  string t;
  int LINES= 0;
  while (getline(studentFile, t)){
    LINES+=1;
  }
  cout << "Lines : " << LINES << endl;
  studentFile.close();
  studentFile.clear();

  //manipulating data in the file (easy way with no string)
  studentFile.open("./students.txt");
  vector <double> v[LINES];
  vector <double> finalMark;
  double value; int i = 0; int j= 0;
  while (studentFile >> value){
    v[j].push_back(value);
    //cout << v[i] << " ";
    i++;
    if (i % 4 == 0){
       cout <<"Hello"<< endl;
       j++;
    }
  }
  for (int k(0); k < LINES; k++){
    double sum = 0;
    for (int l(0); l < 4; l++){
      sum += v[k][l];
    }
    finalMark.push_back(sum/4);
  }

  //print v value
  for (int k(0); k < LINES; k++){
    for (int l(0); l < 4; l++){
      cout << v[k][l] << " ";
    }
    cout << endl;
  }
  cout << "Score : " << endl;
  for (int p(0); p < finalMark.size(); p++){
    cout << finalMark[p] << " ";
  }


  cout << endl << "No more operations to do in the file" << endl;
  studentFile.close();
  cout << "----------------------------" << endl;

  ifstream myFile;
  myFile.open("./student.txt");
  if (!myFile.is_open()){
    cout << "can't open the file in question" << endl;
  }

  int const NUMBER_OF_MARKS = 4;
  double grade1,grade2,grade3,grade4;
  string name;
  vector<double> myMark;
  vector<string> myName;
  while (myFile >> name >> grade1 >> grade2 >> grade3 >> grade4){
    myMark.push_back((grade1 + grade2 + grade3 + grade4) / NUMBER_OF_MARKS);
    myName.push_back(name);
  }
  //printing
  for (int i(0);i < myMark.size(); i++){
    cout << "The student " << myName[i] << " has the grade point average of "
      << std::fixed << std::setprecision(2) << myMark[i] << endl;
  }

  cout << endl << "No more operations to do in the file" << endl;
  myFile.close();
  myFile.clear();


  cout << "----------------------------" << endl;
  ifstream my_file;
  my_file.open("./student.txt");
  if (!my_file.is_open()){
    cout << "can't open the file in question" << endl;
    return 1;
  }

  vector <double> final_mark;
  vector <string> my_name;
  string line, values, names;
  while (getline(my_file, line)){
    int counting = 0; double sum = 0;
    istringstream iss(line);
    iss >> names;
    my_name.push_back(names);
    while (iss >> values){
        sum += atof(values.c_str());
        counting++;
    }
    final_mark.push_back(sum/counting);
  }
  for (int i(0);i < final_mark.size(); i++){
    cout << "The student " << my_name[i] << " has the grade point average of "
      << std::fixed << std::setprecision(2) << final_mark[i] << endl;
  }


  cout << endl << "No more operations to do in the file" << endl;
  myFile.close();
  myFile.clear();

  return 0;
}


/*
  #include <iostream>
using namespace std;
int main()
{
    string t;
    getline(cin,t);

    istringstream iss(t);
    string word;
    while(iss >> word) {
        // do stuff with word
    }
}
*/
