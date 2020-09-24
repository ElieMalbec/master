#include "ft_btree.h"
//https://overiq.com/c-programming-101/void-pointers-in-c/


int main(void){
        t_btree *root = btree_create_node((void *) 9);
        root->left = btree_create_node((void *) 7);
        root->right = btree_create_node((void *) 12);
        root->left->left = btree_create_node((void *) 4);
        root->right->right = btree_create_node((void *) 35);
        printf("-----prefix print of root-----\n");//should print 9 7 4 12 35
        btree_print_prefix(root);

        printf("\n\n");
        /*
        printf("-----Applyf_prefix to all of root nodes-----\n");
        btree_apply_prefix(root, &fm);
        btree_print_prefix(root);
        printf("\n\n");
        */

       /*
        printf("-----Applyf_infix to all of root nodes-----\n");
        btree_apply_infix(root, &fm);
        btree_print_infix(root);
        printf("\n\n");
        */

       /*
        printf("-----Applyf_suffix to all of root nodes-----\n");
        btree_apply_suffix(root, &fm);
        btree_print_suffix(root);
        printf("\n\n");
        */

       /*
        printf("-----search_item in root-----\n");
        printf("%d\n", btree_search_item(root, &fm));
        printf("\n\n");
        */

        /*
        printf("-----Levels in root-----\n");
        printf("number of levels of root : %d", btree_level_count(root));
        printf("\n\n");
        */

        /*
        printf("-----Apply_by_level in root-----\n");
        printf(" ", btree_apply_by_level(root, &my_func));
        btree_print_prefix(root);
        printf("\n\n");
        */
    	return 0;
}