#include "ft_btree.h"

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