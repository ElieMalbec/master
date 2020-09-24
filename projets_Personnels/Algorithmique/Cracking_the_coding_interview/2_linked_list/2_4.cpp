//Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x.The partition element x can appear anywhere in the right partition; it does not need to appear between the left and right partitions
//input  3 5 8 5 10 2 1 (thats the linked list) (partition=5)
//result 3 1 2 10 5 5 8

/*Thoughts
We don't actually need that (because parition is given to us) : First we need to get the number of elements of the linked list and get the sum of all of it's elements. After we need to check if the partition value is greater than the average of all data of the linked list.
1 -then we create two linked list (one for the upper bound and one for the lower bound as well) and add the different node and then connect them and return them.
2 -Or we could if the value of the node is in the upper bound we try to search for a lower bound data and just replace their value.
3 -Or we could add every value in a sorted hash map (key = value, value = number of times there is the key in the linked list) then we just need to iterate through the linked list and change the values. Our linked list would become sorted 
*/

#include "main2.h"
#include <iostream>
#include <iterator>

using std::cout;
using std::endl;


int main(void){
    Node *head = new Node(5);
    head->appendToTail(10);
    head->appendToTail(7);
    head->appendToTail(8);
    head->appendToTail(9);
    head->appendToTail(5);
    cout << "Initital : ";
    head->display();
    cout << endl;
/*
    head->remove_duplicates2();
    head->display();
    cout << endl;
*/
    head = head->partition(head, 6);
    cout << "Final : ";
    head->display();
    cout << endl;
    return 0;
}