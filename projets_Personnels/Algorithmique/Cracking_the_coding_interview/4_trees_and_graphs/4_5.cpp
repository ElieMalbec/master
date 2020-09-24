//Implement a function to check if a binary tree is a binary search tree

/*Thoughts
A binary search tree is a tree where each node on the left is lower than the parent node and each node on the right is higher than the parent node.
wo we save the value of the parent node and we compare with the left and the right children.
*/

#include <iostream>
#include <limits>

using std::cout;
using std::endl;

struct bin{
    int data;
    struct bin *right;
    struct bin *left;

    bin(int data){
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
    } 
};

void prefix(struct bin *tree){
    if (tree == nullptr) return;
    cout << tree->data << " ";
    prefix(tree->left);
    prefix(tree->right);
}

/*
bool isBinary(struct bin *tree, int min, int max){
    bool right = true; bool left = true;
    if (tree == nullptr) return false;
    if (tree != nullptr && tree->left == nullptr && tree->right == nullptr) return true;
    if (tree != nullptr && tree->left !=  nullptr && tree->right == nullptr && tree->data > tree->left->data){
        return isBinary(tree->left, std::numeric_limits<int>::min(), tree->data);
    }
    if (tree != nullptr && tree->left ==  nullptr && tree->right != nullptr){
        right = isBinary(tree->right, tree->data ,std::numeric_limits<int>::max());
    }
    if ((tree->left != nullptr && tree->right != nullptr)&&(tree->data > tree->left->data && tree->data < tree->right->data)){
        left = isBinary(tree->left, std::numeric_limits<int>::min(), tree->data);
        right = isBinary(tree->right, tree->data, std::numeric_limits<int>::max());
    }
    else {return false;}
    return (right && left);
}
*/

int main(void){
    bin *tree = new bin(5);
    tree->left = new bin(2);
    tree->right = new bin(7);

    tree->left->left = new bin(-1);
    tree->left->right = new bin(6);
    tree->right->left = new bin(6);
    tree->right->right = new bin(12);

    tree->left->left->left = new bin(-3);
    tree->left->left->right = new bin(0);
    
    prefix(tree);
    cout << endl;

    cout << "is binary (0-no; 1-yes) : " << isBinary(tree,std::numeric_limits<int>::min(),std::numeric_limits<int>::max()) << endl;

    return 0;
}
