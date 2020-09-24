// First Common Ancestor: Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.

/*Thoughts
if we could store data we could just store every parent node for the first node and then find the latest for the second node and return that one (if A B C D and then B A then B is the one in commun)
we could add a visited bool to know if we already had been there, if yes then we return that node
i suppose there is a way to go up also with a pointer
*/

#include <iostream>


int main(void){
    std::cout << (11 &(~0 << 2)) << std::endl;
    
    return 0;
}
