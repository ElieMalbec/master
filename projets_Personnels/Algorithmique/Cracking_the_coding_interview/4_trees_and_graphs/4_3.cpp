// List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

/*Thoughts
First we will need an array of pointers who will contains the linked list.
Then we must go through our binary tree with a BFS.
Then we must know when we must create another linked list. 
For example if our depth is 4 then 2^0 = 1 node in a linked list, 
                        then 2^1 = 2 nodes in the second linked list 
                        then 2^2 = 4 nodes in the third linked list
                        then 2^3 = 8 nodes in the fourth linked list (in the maximum)
                        so while (numberofNode < 2^n && !q.empty())
*/


#include <iostream>
#include <vector>
#include <queue>
#include <tgmath.h>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::list;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
struct LinkedList{
    int data;
    LinkedList *next;

    LinkedList(int data){
        this->data = data;
        next = nullptr;
    }
};

vector <list <LinkedList>> list_of_depths(Node * root){
    int power = 0;
    int nbOfLinkedList = std::pow(2, power);
    vector <list <LinkedList>> l;
    queue<int> q;
    q.push(root->data);

    LinkedList a(root->data);


    list <LinkedList> current;
    current.push_back(a);
    while (!q.empty()){
        
        //current = new vector<LinkedList>;
    }

}

int main(void){
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);

    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    tree->right->left = new Node(6);
    tree->right->left = new Node(7);

    tree->left->left->left = new Node(8);
    tree->left->left->right = new Node(9);


    vector <list <LinkedList>> my_list = list_of_depths(tree);

    return 0;
}