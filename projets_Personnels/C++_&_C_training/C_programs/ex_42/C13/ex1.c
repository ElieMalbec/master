#include "ft_btree.h"
int a = 10;
void    btree_apply_prefix(t_btree *root, void (*applyf)(void *)){
    if (root == NULL) return ;

    applyf(root->item);
    btree_apply_prefix(root->left, applyf);
    btree_apply_prefix(root->right, applyf);
}

void    fm(void *item){
    //int *x = malloc(sizeof(int));
    //x = 5;
    
    item = &a;
}

int main(void){
        t_btree *root = btree_create_node((void *) 9);
        root->left = btree_create_node((void *) 7);
        root->right = btree_create_node((void *) 12);
        root->left->left = btree_create_node((void *) 4);
        root->right->right = btree_create_node((void *) 35);
        printf("-----prefix print of root-----\n");//should print 9 7 4 12 35
        btree_print_prefix(root);

        printf("\n\n");
        printf("-----Applyf to all of root nodes-----\n");
        btree_apply_prefix(root, &fm);
        btree_print_prefix(root);
        printf("\n\n");
    	return 0;
}