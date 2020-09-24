//Given a sorted(increased order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height

/*Thoughts
we want the same number of nodes on the right and on the left. To do that we must use the fact that our array is sorted, so we just have to take the middle of the array and use it as our root tree node.
then the left the array goes on the left side of the tree and the right of the array goes on the right of the tree.
i thought about moving two by two into each sub array to get the best tree possible but i didn't see that we just have to take the middle of the subarray
*/

//1-insert into th tree the middle element of the array
//2-insert into the left subtree the left subarray elements
//3-Same as 2 but on the right
//4-recurse

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

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

struct bin *createMinimalBST2(vector<int> arr, int start, int end){
    if (start > end) return nullptr;
    int mid = (start+end)/2;
    struct bin *n = new bin(arr[mid]);
    n->left = createMinimalBST2(arr, start, mid-1);
    n->right = createMinimalBST2(arr,mid+1, end);
    return n;
}

struct bin *createMinimalBST(vector<int> arr){
    if (arr.size() == 0) return nullptr;
    return createMinimalBST2(arr, 0, ((int) arr.size()) - 1);
}

void prefix(struct bin *tree){
    if (tree == nullptr) return;
    cout << tree->data << " ";
    prefix(tree->left);
    prefix(tree->right);
}

int main(void){
    int arr[] = {1,2,3,4,5,6,7};
    vector<int> arr2{1,2,3,4,5,6,7};

    struct bin *tt = createMinimalBST(arr2);
    prefix(tt);

   return 0;
}