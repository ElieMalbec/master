// Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree. You may assume that each node has a link to its parent.

/*Thoughts
We just gonna use how inorder traversal work
So we if the node has two nodes we take on level above (if it has not parent like the root node we go to the most left of the right subtree)
If the node has one node (if it has on the left node) we take one level higher
If the node has one node (if it has on the right node) we take the most left of the right subtree
if it has no children node we call again our function on the node above.
*/

#include <iostream>

using std::cout;
using std::endl;

struct bin{
    int data;
    struct bin *right;
    struct bin *left;
    struct bin *parent;

    bin(int data){
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
        this->parent = nullptr;
    } 
};

void inorder(struct bin *tree){
    if (tree == nullptr) return;
    inorder(tree->left);
    if (tree->parent != nullptr){
        cout << tree->data << " & value of parent : " << tree->parent->data << endl;
    }
    else {
        cout << tree->data << endl;
    }
    inorder(tree->right);
}

int findNextNode(struct bin *tree){
    if (tree == nullptr) return -100;
    /*if (tree->left == nullptr && tree->right == nullptr){
        return tree->parent->parent->data;
    }*/
    if (tree->right != nullptr){
        struct bin *temp = tree->right;
        while (temp->left != nullptr){
            temp = temp->left;
        }
        return temp->data;
    }
    else {
        struct bin * q = tree;
        struct bin * x = tree->parent;
        while (x != nullptr && x->right!= nullptr){
            q = x;
            x = x->parent;
            //if (x == nullptr) break;
        }
        return x->data;
    }
    
}

int main(void){
    bin *tree = new bin(5);
    tree->left = new bin(2);
    tree->right = new bin(7);

    tree->left->left = new bin(-1);
    tree->left->right = new bin(3);
    tree->right->left = new bin(6);
    tree->right->right = new bin(12);

    tree->left->left->left = new bin(-3);
    tree->left->left->right = new bin(0);

    tree->left->parent = tree;
    tree->right->parent = tree;

    tree->left->left->parent = tree->left;
    tree->left->right->parent = tree->left;

    tree->left->left->left->parent = tree->left->left;
    tree->left->left->right->parent = tree->left->left;

    tree->right->left->parent = tree->right;
    tree->right->right->parent = tree->right;
    
    inorder(tree);
    cout << endl;

    cout << tree->data << " " << findNextNode(tree) << endl;
    cout << tree->left->data << " " << findNextNode(tree->left) << endl;
    cout << tree->left->right->data << " " << findNextNode(tree->left->right) << endl;
    cout << tree->left->left->left->data << " " << findNextNode(tree->left->left->left) << endl;
    cout << tree->left->left->right->data << " " << findNextNode(tree->left->left->right) << endl;

    return 0;
}