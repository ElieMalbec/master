//

/*Thoughts

*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::vector;

struct Node{
    int data;
    struct Node *right;
    struct Node *left;

    Node(int data){
        this->data = data;
        right = nullptr;
        left = nullptr;
    }
};

Node *copyNode(Node * node){
    if (node == nullptr) return nullptr;
    Node * newNode = new Node(node->data);
    newNode->right = node->right;
    newNode->left = node->left;
    return newNode;
}

void print(Node * node){
    if (node){
        cout << node->data;
    }
    else {
        cout << "null";
    }
    cout << endl;
}

int main(void){
    Node *root = new Node(3);
    root->right = new Node(5);

    print(root);
    print(root->right);
    print(root->left);
    cout << "--copyNode()--" << endl;
    Node * cpy = copyNode(root);
    print(root);
    print(root->right);
    print(root->left);
    cout << "--print copy--" << endl;
    print(cpy);
    print(cpy->right);
    print(cpy->left);
    cout << &cpy << " "<< &root << endl;
    cout << &cpy->right << " "<< &root->right << endl;
    cout << &cpy->left << " "<< &root->left << endl;

    return 0;
}