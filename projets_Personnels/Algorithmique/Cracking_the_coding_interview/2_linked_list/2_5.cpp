//you have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list

/*Thoughts
The idea is that to get the correct number we need to loop through the linked list and we calculate this : number = number + list->data * coef. Where number begins at 0 and coeff begins at 1 and then x10 ( so 1 then 10 then 100, etc)
That is for the first part.

The other part we need to know first how many numbers there are. Then we multiply our coeff variable (we use a loop), so we get the correct number. And then we do the same as before but we divise our coeff by 10 every time we have a new Node
Or if it's a double linked list we could go to the end of it and then do what we do in the first place. 

Finally we just add both numbers.
*/

//add then on the go, save the carry

#include "main2.h"
#include <iostream>
#include <iterator>

using std::cout;
using std::endl;


int main(void){
/*
    Node *head = new Node(5);
    head->appendToTail(10);
    head->appendToTail(7);
    head->appendToTail(8);
    head->appendToTail(9);
    head->appendToTail(5);
    cout << "Initital : ";
    head->display();
    cout << endl;
*/
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
    Node *l2 = new Node(0);
    l2->appendToTail(0);
    l2->appendToTail(1);

    Node *l1 = new Node(5);
    l1->appendToTail(5);
    l1->appendToTail(5);
    l1->appendToTail(5);

    cout << "Value of the reverse order sum of l1 and l2 : " << l1->sum_list_reverse_order(l2,l1) << endl;
    cout << "Value of the forward sum of l1 and l2 : " << l1->sum_list_forward_order(l2,l1) << endl;

    return 0;
}