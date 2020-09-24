#include <stdio.h>

#if !defined(F)
    #define F 0
#endif
#ifndef T
    #define T 1
#endif

#if !defined(FF)
    #define FF "hi"
#endif
#ifndef TT
    #define TT "hey"
#endif


#ifdef F
    #define HELLO "Hello world!"
#endif

#define toString(s) #s
#define _toString(s) toString(s)

/* //NOT GOOD BECAUSE NO BLOCKS IN YOUR DEFINE
#define SWAP(a,b) \
\
int temp = a ;\
a = b;\
b = temp;\
\
*/

//BETTER
#define SWAP(a,b)   \
{                   \
    int temp = a ;      \
    a = b;              \
    b = temp;           \
}                   \

int main(void){
    int t = T; int f = F;

    printf("1-%d and %d\n", t,f); //works
    printf("2-t : " _toString(T) " and f : " _toString(F) "\n"); //works
    printf("3-tt : " _toString(TT) " and ff : " _toString(FF) "\n"); //works strangely
    printf("4-tt : " TT " and ff : " FF "\n"); //works
    printf("5-tt : %s and ff : %s\n", TT, FF); //works
    printf("6-t : %d and f : %d\n", T, F); //works
    int first = 3; int second  = 5;
    printf("%d et %d\n", first, second);
    SWAP(first, second);
    printf("%d et %d\n", first, second);
    //temp = 8;
    //printf("%d \n", temp);
    return 0;
}