struct node {
  int key;
  struct node *left;
  struct node *right;
};

//searching a key
struct node * search(struct *root, int key){
  if (key == root->key || root == NULL){
    return root;
  }
  else if (root->key < key){
    return search(root->right, key);
  }
  return search(root->left, key);
}

//insertion of a key
struct node *insertNode(int item){
  struct node * Node = malloc(sizeof(struct node));
  Node->key = item;
  Node->left = NULL;
  Node->right = NULL;
  return Node;
}

struct node * insertion(struct node *root, int key){
  if (root == NULL){
    return (insertNode(key));
  }
  if (key > root->key){
    node->left = insertion(root->right, key);
  }
  if (key < root->key){
    node->right = insertion(root->left, key);
  }
  return root;
}

//time complexity
// O(h) for worst case of search and insert
//inorder traversal produces
//delete a key
struct node * delete(struct node * root, int key){
  if (root = NULL) return root;
  0
  if (key < root->key){
    root->left = delete(root->left, key);
  }
  else if (key > root->key){
    root->right = delete(root->right, key)
  }
  else {
    if (root->left == NULL){
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL){
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node * temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
//time complexity is O(h) for deletion

//advantages of BST over Hash table
