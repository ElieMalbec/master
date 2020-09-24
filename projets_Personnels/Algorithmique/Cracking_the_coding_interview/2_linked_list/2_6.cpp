//implement a function to check if a function is a palindrome


/*Thoughts
I suppose you can have palindrome on numbers. 
We could iterate through the linked list and hold every value in a array and then check again.
On a double linked list we just need to pointers one on the first and one on the last Node and then check.

We could create a new linked list recursively that begins by the last and then we have to loop through to see if they are correct (but it's takes spaces)
*/

//we could use a a stack

#include "main2.h"
#include <iostream>
#include <iterator>

using std::cout;
using std::endl;


int main(void){

    Node *head = new Node(5);
    head->appendToTail(6);
    head->appendToTail(7);
    head->appendToTail(7);
    head->appendToTail(6);
    head->appendToTail(5);
    cout << "Initital : ";
    head->display();
    cout << endl;

/*
    head->remove_duplicates2();
    head->display();
    cout << endl;
*/
/*
    head = head->partition(head, 6);
    cout << "Final : ";
    head->display();
    cout << endl;
*/

/*
    Node *l2 = new Node(0);
    l2->appendToTail(0);
    l2->appendToTail(1);

    Node *l1 = new Node(5);
    l1->appendToTail(5);
    l1->appendToTail(5);
    l1->appendToTail(5);

    cout << "Value of the reverse order sum of l1 and l2 : " << l1->sum_list_reverse_order(l2,l1) << endl;
    cout << "Value of the forward sum of l1 and l2 : " << l1->sum_list_forward_order(l2,l1) << endl;
*/

    cout << head->is_palindrome(head) << endl;
    return 0;
}

/*A slow fast method traversal in linked list
slow = head;
fast = head;
while (fast != null && fast.next!= null){
    stack.push(slow.data);
    slow = slow->next;
    fast = fast->next->next; 
}
*/