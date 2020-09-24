#include "ft_btree.h"

t_btree *btree_create_node(void *item){
      t_btree * newTree;

      if (!(newTree = malloc(sizeof(t_btree)))){
           return NULL;    
      }
      newTree->left = NULL;
      newTree->right = NULL;
      newTree->item = item;

      return newTree;
}

/*
void    btree_print_prefix(t_btree *root){
    if (root == NULL) return ;
    printf("%p ",root->item);
    btree_print_prefix(root->left);
    btree_print_prefix(root->right);
}
*/

int main(void){
        t_btree *root = btree_create_node((void *) 9);
        btree_print_prefix(root);
    	return 0;
}
