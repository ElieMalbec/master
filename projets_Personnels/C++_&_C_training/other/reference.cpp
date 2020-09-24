
#include<iostream> 
using namespace std; 
  
int main() 
{ 
  int x = 10; 
  
  // ref is a reference to x. 
  int& ref = x; 
  cout << "x = " << x << endl ; 
  cout << "ref = " << ref << endl ;

  // Value of x is now changed to 20 
  ref = 20; 
  cout << "x = " << x << endl ; 
  cout << "ref = " << ref << endl ; 

  
  // Value of x is now changed to 30 
  x = 30; 
  cout << "ref = " << ref << endl ; 
  cout << "x = " << x << endl ; 
  return 0; 
} 

/* SWAP FUNCTION
void swap (int& first, int& second) 
{ 
    int temp = first; 
    first = second; 
    second = temp; 
} 
  
int main() 
{ 
    int a = 2, b = 3; 
    swap( a, b ); 
    cout << a << " " << b; 
    return 0; 
} 
*/

/* AVOID COPYING LARGE STRUCTURES
struct Student { 
   string name; 
   string address; 
   int rollNo; 
} 
  
// If we remove & in below function, a new 
// copy of the student object is created.  
// We use const to avoid accidental updates 
// in the function as the purpose of the function 
// is to print s only. 
void print(const Student &s) 
{ 
    cout << s.name << "  " << s.address << "  " << s.rollNo; 
} 
*/

/* FOR LOOPS
int main()  
{  
    vector<int> vect{ 10, 20, 30, 40 };  
  
    // We can modify elements if we  
    // use reference 
    for (int &x : vect)  
        x = x + 5; 
  
    // Printing elements 
    for (int x : vect)  
       cout << x << " ";  
  
    return 0;  
}  */

/* FOR EACH LOOPS 
int main()  
{  
    vector<string> vect{"geeksforgeeks practice",  
                     "geeksforgeeks write", 
                     "geeksforgeeks ide"};  
  
    // We avoid copy of the whole string 
    // object by using reference. 
    for (const auto &x : vect)  
       cout << x << endl;  
  
    return 0;  
} */
/* https://www.geeksforgeeks.org/pointers-vs-references-cpp/ */
