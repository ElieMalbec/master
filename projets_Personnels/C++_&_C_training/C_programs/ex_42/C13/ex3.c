#include "ft_btree.h"

void    suffix(t_btree *root, void (*applyf)(void *)){
    if (!root) return ;

    btree_apply_infix(root->left, applyf);
    btree_apply_infix(root->right, applyf);
    applyf(root->item);
}