//Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

/*Thoughts
we could create loop and add every addresses of each Node in a hash and check if one is the the same as one before (one in the hash)

*/

//We need first to detect if there is a loop; for that we need to use the runner method : un pointer go fast and another go slow, at one point they will collide.

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
    Node *t = head;
    while (t->next != nullptr){
        t = t->next;
    }
    t->next = head->next->next;
    Node *p = head;
    for (int i(0); i < 5; i++){
        cout << p->data << " ";
        p = p->next;
    }
    //cout << "Initital : ";
    //head->display();
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


    cout << l1->intersection(l1, l2) << endl;
*/

    return 0;
}