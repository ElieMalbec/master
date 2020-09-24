//Write code to remove duplicates from an unsorted linked list
//how you wwould you solve it if you have no temporary buffer

/*Thoughts
First we need to know that it's a single ou double linked list. We also need to know what kind of data it is (int, double).
We just need to iterate through our linked list from the beginning to the end and then remove the node that corresponds to the data we want to delete.

Didn't understood corectly the exercice
Then we need to check if there is a duplicate, we could create 2 arrays with one containing numbers who are not duplicate and one who are.
We would have to do iterate through the linked and if we found a duplicate we add it to the array, we continue until all numbers are on both arrays (not very efficient)
Or we can use a hash table
Or we could sort the linked list and check for neighbours
we can also use two loops
--> Again, didn't understood corectly that you need to keep the first value and not delete every node who have duplicates
*/

#include "main2.h"
//#include "List.cpp"
#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::vector;
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

/*
    List *list = new List();
    list->createnode(5);
    list->createnode(6);
    list->createnode(7);
    list->createnode(8);
    list->createnode(9);
    list->createnode(5);
    list->display();
    cout << endl;
*/
/*
    list->delete_first();
    list->delete_last();
    list->delete_position(2);
    list->display();
    cout << endl;
*/
/*
    list->insert_start(5);
    list->insert_position(3,12);
    list->display();
    cout << endl;
*/
/*
    list->remove_duplicates();
    list->display();
    cout << endl;
*/
    return 0;
}