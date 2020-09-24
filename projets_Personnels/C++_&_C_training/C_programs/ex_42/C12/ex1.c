#include "ft_list.h"

void    ft_list_push_front(t_list **begin_list, void *data){
    if (*begin_list == NULL){
        *begin_list = ft_create_elem(data);
        return ;
    }
    else {
        t_list *tmp = ft_create_elem(data);
        tmp->next = *begin_list;
        *begin_list = tmp; // not begin_list = &tmp
    }
}

int     main(void){
    t_list **root = malloc(sizeof(t_list **));
    *root = ft_create_elem((void *) 12);
    ft_list_push_front(root, (void *) 9);
    ft_print_my_linked_list(root);

    printf("---Empty root---\n");
    t_list **new_root = malloc(sizeof(t_list **));
    ft_list_push_front(new_root, (void *) 150);
    ft_print_my_linked_list(new_root);

    return 0;
}