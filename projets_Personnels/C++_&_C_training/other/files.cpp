
/* File Handling with C++ using ifstream & ofstream class object*/
/* To write the Content in File*/
/* Then to read the content of file*/
#include <iostream> 
  
/* fstream header file for ifstream, ofstream,  
  fstream classes */
#include <fstream> 
  
using namespace std; 
  
// Driver Code 
int main() 
{ 
    // Creation of ofstream class object 
    ofstream fout; 
  
    string line; 
  
    // by default ios::out mode, automatically deletes 
    // the content of file. To append the content, open in ios:app 
    // fout.open("sample.txt", ios::app) 
    fout.open("sample.txt"); 
  
    // Execute a loop If file successfully opened 
    while (fout) { 
  
        // Read a Line from standard input 
        getline(cin, line); 
  
        // Press -1 to exit 
        if (line == "-1") 
            break; 
  
        // Write line in file 
        fout << line << endl; 
    } 
  
    // Close the File 
    fout.close(); 
  
    // Creation of ifstream class object to read the file 
    ifstream fin; 
  
    // by default open mode = ios::in mode 
    fin.open("sample.txt"); 
  
    // Execute a loop until EOF (End of File) 
    while (fin) { 
  
        // Read a Line from File 
        getline(fin, line); 
  
        // Print line in Console 
        cout << line << endl; 
    } 
  
    // Close the file 
    fin.close(); 
  
    return 0; 
} 

/*
// File Handling with C++ using fstream class object 
// To write the Content in File 
// Then to read the content of file
#include <iostream> 
  
// fstream header file for ifstream, ofstream,  
//   fstream classes 
#include <fstream> 
  
using namespace std; 
  
// Driver Code 
int main() 
{ 
    // Creation of fstream class object 
    fstream fio; 
  
    string line; 
  
    // by default openmode = ios::in|ios::out mode 
    // Automatically overwrites the content of file, To append 
    // the content, open in ios:app 
    // fio.open("sample.txt", ios::in|ios::out|ios::app) 
    // ios::trunc mode delete all conetent before open 
    fio.open("sample.txt", ios::trunc | ios::out | ios::in); 
  
    // Execute a loop If file successfully Opened 
    while (fio) { 
  
        // Read a Line from standard input 
        getline(cin, line); 
  
        // Press -1 to exit 
        if (line == "-1") 
            break; 
  
        // Write line in file 
        fio << line << endl; 
    } 
  
    // Execute a loop untill EOF (End of File) 
    // point read pointer at beginning of file 
    fio.seekg(0, ios::beg); 
  
    while (fio) { 
  
        // Read a Line from File 
        getline(fio, line); 
  
        // Print line in Console 
        cout << line << endl; 
    } 
  
    // Close the file 
    fio.close(); 
  
    return 0; 
} 
*/

