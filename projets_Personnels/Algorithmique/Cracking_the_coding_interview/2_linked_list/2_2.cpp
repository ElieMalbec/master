//Implement an algorithm to find the kth to last element in a singly linked list.

/*Thoughts
I thought that was to return the Kth element but from the start...
if we know list size we just iterate to listsize - k and then return that node
if we don't we could use two pointers and then the first one go to k, then we iterate both of them until the first one is nullptr
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

    head = head->kth_to_last(head, 1);
    head->display();
    cout << endl;
    return 0;
}