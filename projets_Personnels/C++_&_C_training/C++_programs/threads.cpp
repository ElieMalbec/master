// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void foo() 
{
  // do stuff...
}

void bar(int x)
{
  // do stuff...
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;
}
/*

// CPP program to demonstrate multithreading 
// using three different callables. 
#include <iostream> 
#include <thread> 
using namespace std; 
  
// A dummy function 
void foo(int Z) 
{ 
    for (int i = 0; i < Z; i++) { 
        cout << "Thread using function"
               " pointer as callable\n"; 
    } 
} 
  
// A callable object 
class thread_obj { 
public: 
    void operator()(int x) 
    { 
        for (int i = 0; i < x; i++) 
            cout << "Thread using function"
                  " object as  callable\n"; 
    } 
}; 
  
int main() 
{ 
    cout << "Threads 1 and 2 and 3 "
         "operating independently" << endl; 
  
    // This thread is launched by using  
    // function pointer as callable 
    thread th1(foo, 3); 
  
    // This thread is launched by using 
    // function object as callable 
    thread th2(thread_obj(), 3); 
  
    // Define a Lambda Expression 
    auto f = [](int x) { 
        for (int i = 0; i < x; i++) 
            cout << "Thread using lambda"
             " expression as callable\n"; 
    }; 
  
    // This thread is launched by using  
    // lamda expression as callable 
    thread th3(f, 3); 
  
    // Wait for the threads to finish 
    // Wait for thread t1 to finish 
    th1.join(); 
  
    // Wait for thread t2 to finish 
    th2.join(); 
  
    // Wait for thread t3 to finish 
    th3.join(); 
  
    return 0; 
} 
*/

/* LAMBDA FUNCTION DIRECTLY TO THE CONSTRUCTOR
std::thread thread_object([](params) { 
    // Do Something 
};, params); 
*/
/* GENERIC LAMBDA
// Define a lamda expression 
auto f = [](params) { 
    // Do Something 
}; 
  
// Pass f and its parameters to thread  
// object constructor as 
std::thread thread_object(f, params); 
*/









/*
#include <iostream>
#include <boost/thread.hpp>

using std::cout;
using std::endl;

void task1(){
  cout << "Task 1" << endl;
}
void task2(){
  cout << "Task 2" << endl;
}

int main(){
  boost::thread t1 = thread(task1);
  boost::thread t2 = thread(task2);

  t2.join();
  t1.join();
  return 0;
}
*/