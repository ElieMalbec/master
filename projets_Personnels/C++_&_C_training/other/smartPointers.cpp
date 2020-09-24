//https://www.acodersjourney.com/top-10-dumb-mistakes-avoid-c-11-smart-pointers/
#include <iostream> 
using namespace std; 
  
// A generic smart pointer class 
template <class T> 
class SmartPtr { 
    T* ptr; // Actual pointer 
public: 
    // Constructor 
    explicit SmartPtr(T* p = NULL) { ptr = p; } 
  
    // Destructor 
    ~SmartPtr() { delete (ptr); } 
  
    // Overloading dereferncing operator 
    T& operator*() { return *ptr; } 
  
    // Overloading arrow operator so that 
    // members of T can be accessed 
    // like a pointer (useful if T represents 
    // a class or struct or union type) 
    T* operator->() { return ptr; } 
}; 
  
int main() 
{ 
    SmartPtr<int> ptr(new int()); 
    *ptr = 20; 
    cout << *ptr; 
    return 0; 
} 

/* unique_ptr
#include <iostream> 
using namespace std; 
#include <memory> 
  
class Rectangle { 
    int length; 
    int breadth; 
  
public: 
    Rectangle(int l, int b) 
    { 
        length = l; 
        breadth = b; 
    } 
  
    int area() 
    { 
        return length * breadth; 
    } 
}; 
  
int main() 
{ 
  
    unique_ptr<Rectangle> P1(new Rectangle(10, 5)); 
    cout << P1->area() << endl; // This'll print 50 
  
    // unique_ptr<Rectangle> P2(P1); 
  
    unique_ptr<Rectangle> P2; 
    P2 = move(P1); 
  
    // This'll print 50 
    cout << P2->area() << endl; 
  
    // cout<<P1->area()<<endl; 
    return 0; 
} 
*/

/*shared_ptr
#include <iostream> 
using namespace std; 
#include <memory> 
  
class Rectangle { 
    int length; 
    int breadth; 
  
public: 
    Rectangle(int l, int b) 
    { 
        length = l; 
        breadth = b; 
    } 
  
    int area() 
    { 
        return length * breadth; 
    } 
}; 
  
int main() 
{ 
  
    shared_ptr<Rectangle> P1(new Rectangle(10, 5)); 
    // This'll print 50 
    cout << P1->area() << endl; 
  
    shared_ptr<Rectangle> P2; 
    P2 = P1; 
  
    // This'll print 50 
    cout << P2->area() << endl; 
  
    // This'll now not give an error, 
    cout << P1->area() << endl; 
  
    // This'll also print 50 now 
    // This'll print 2 as Reference Counter is 2 
    cout << P1.use_count() << endl; 
    return 0; 
} 
*/

/*weak_ptr (same as shared_ptr but no reference counter
*/
