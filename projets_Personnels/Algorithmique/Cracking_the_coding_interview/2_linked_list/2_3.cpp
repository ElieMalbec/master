//Implement an algorithm to delete a node in the middle (any node but not the first and last) of a singly linked list, given only access to that node.

/*Thoughts
if we had access to the head
So we could check that the linked list has more than two elements first. Then we could get the number of elements by counting them.
After that we could divise by two that number and then iterate on the linked to find the Node to delete and finally delete it.
we don't have access to the head.
*/


#include "main2.h"
#include <iostream>
#include <iterator>

using std::cout;
using std::endl;


int main(void){
    Node *head = new Node(5);
    head->appendToTail(6);
    head->appendToTail(7);
    head->appendToTail(8);
    head->appendToTail(9);
    head->appendToTail(10);
    head->display();
    cout << endl;

    head->remove_duplicates2();
    head->display();
    cout << endl;

    head->middle_node(head->next);
    head->display();
    cout << endl;
    return 0;
}