//don't put the functions inside the .h
//use .c file and compile with them in the makefile
#ifndef FT_BTREE
#define FT_BTREE
#include <stdio.h>
#include <stdlib.h>


typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void		    *item;
}			        t_btree;


void    btree_print_prefix(t_btree *root){
    if (!root) return ;
    
    printf("%p ",root->item);
    btree_print_prefix(root->left);
    btree_print_prefix(root->right);
}

void    btree_print_infix(t_btree *root){
    if (!root) return ;
    
    btree_print_prefix(root->left);
    printf("%p ",root->item);
    btree_print_prefix(root->right);
}

void    btree_print_suffix(t_btree *root){
    if (!root) return ;
    
    btree_print_prefix(root->left);
    btree_print_prefix(root->right);
    printf("%p ",root->item);
}


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

void    btree_apply_prefix(t_btree *root, void (*applyf)(void *)){
    if (!root) return ;

    applyf(root->item);
    btree_apply_prefix(root->left, applyf);
    btree_apply_prefix(root->right, applyf);
}

void    btree_apply_infix(t_btree *root, void (*applyf)(void *)){
    if (!root) return ;

    btree_apply_infix(root->left, applyf);
    applyf(root->item);
    btree_apply_infix(root->right, applyf);
}

void    suffix(t_btree *root, void (*applyf)(void *)){
    if (!root) return ;

    btree_apply_infix(root->left, applyf);
    btree_apply_infix(root->right, applyf);
    applyf(root->item);
}

//ex4
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
}

//ex5
void    *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void*)){
    if (!root) return NULL;
    btree_search_item(root->left, data_ref, cmpf);
    if (cmpf(root->item, data_ref) == 0){
        return root->item;
    }
    btree_search_item(root->left, data_ref, cmpf);
    return NULL;
}

//ex6 root is always level 1
int btree_level_count(t_btree *root){
    if (!root) return 0;
    int depth_left = btree_level_count(root->left);
    int depth_right = btree_level_count(root->right);

    if (depth_left >= depth_right){
        return depth_left + 1;
    }
    else {
        return depth_right + 1;
    }
}


#endif
