#include "ft_btree.h"

void    btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *)){
    if (!*root){
        btree_create_node(item);
	return ;
    }

    if (cmpf(item, (*root)->item) < 0){//item is smaller go left
        if (!(*root)->left){
            (*root)->left = btree_insert_data(&(*root)->left, item, cmpf);
        }
        else{
            btree_insert_data(&(*root)->left, item, cmpf);
        }
    }
    else if (cmpf(item, (*root)->item) > 0){//item is bigger
        if (!(*root)->right){
            root->right = btree_insert_data(&(*root)->right, item, cmpf);
        }
        else {
            btree_insert_data(&(*root)->right, item, cmpf);
        }
    }
    else {//if == 0 we just leave
        return ;
    }
