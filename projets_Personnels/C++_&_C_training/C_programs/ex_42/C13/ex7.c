#include "ft_btree.h"
/**
 * NOT WORKING
*/
void    btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first)){
    if (!root) return;
    
    int height = btree_level_count(root);
    int i = 1;

    while (i < height){
        my_func(root, i, 1, applyf);
        i++;
    }
    //compte les nveaux
    //de 1 à niveaux : faire call func()
    
}

void    my_func(t_btree *root, int level, int first, void (*applyf)(void *item, int current_level, int is_first)){
    if (!root) return;

    if (first == 1){
        applyf(root->item, level, 0);
    }
    else {
        my_func(root->left, );
    }
}


//faire une queue
    //ajouter root à la queue
    //tant que queue est pas vide
    //utiliser la fonction sur le top
    //dépiler 
    //ajouter les noeuds adjacents