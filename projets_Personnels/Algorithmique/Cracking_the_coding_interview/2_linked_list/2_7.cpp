//Given two singly linked lists, determine if the two lists intersect.Return the intersecting node. Note that the intersection is defined based on reference, not value. That is , if the kth node of the first linked list of the first linked list is the exact same node by reference as the jth node of the second linked list, then they are intersecting.

/*Thoughts
A bruteforce method woudl be to try all the nodes O(l1*l2) in time.
Or we could create an array of dictionnary. Each array would be for a a value in the linked list (key = )
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
    return 0;
}