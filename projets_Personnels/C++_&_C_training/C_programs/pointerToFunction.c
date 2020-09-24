#include <stdio.h> 
// A normal function with an int parameter 
// and void return type 
int fun(int a) 
{ 
	printf("Value of a is %d\n", a); 
  	return a;
} 

int main() 
{ 
	// fun_ptr is a pointer to function fun() 
	int (*fun_ptr)(int) = &fun; 

	/* The above line is equivalent of following two 
	void (*fun_ptr)(int); 
	fun_ptr = &fun; 
	*/

	// Invoking fun() using fun_ptr 
	int c = (*fun_ptr)(10); 

	return 0; 
}

/* EASIER WAY
#include <stdio.h> 
// A normal function with an int parameter 
// and void return type 
void fun(int a) 
{ 
    printf("Value of a is %d\n", a); 
} 
  
int main() 
{  
    void (*fun_ptr)(int) = fun;  // & removed 
  
    fun_ptr(10);  // * removed 
  
    return 0; 
}
*/
