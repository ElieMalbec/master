#include "ft_list.h"

void    ft_list_push_back(t_list **begin_list, void *data){
    t_list ** tmp;

    tmp = begin_list;
    if (*begin_list == NULL){
        *begin_list = ft_create_elem(data);
        return ;
    }
    while ((*tmp)->next != NULL){
        tmp = &(*tmp)->next;
    }
    (*tmp)->next = ft_create_elem(data);
}

int     main(void){
    printf("---root---\n");
    t_list **root = malloc(sizeof(t_list **));
    *root = ft_create_elem((void *) 12);
    ft_list_push_front(root, (void *) 9);
    ft_print_my_linked_list(root);

    printf("---new root---\n");
    t_list **new_root = malloc(sizeof(t_list **));
    ft_list_push_front(new_root, (void *) 150);
    ft_print_my_linked_list(new_root);

    printf("\n\n");

    printf("---size root---\n");
    printf("\t%d\n", ft_list_size(*root));
    printf("---size new_root---\n");
    printf("\t%d\n", ft_list_size(*new_root));
    printf("---size empty_root---\n");
    t_list *empty_root = NULL;
    printf("\t%d\n", ft_list_size(empty_root));
    
    printf("\n\n");

    printf("---last_element of root---\n");
    t_list *last_of_root = ft_list_last(*root);
    printf("\t%p\n", last_of_root->data);
    printf("---last_element of new_root---\n");
    t_list *last_of_newroot = ft_list_last(*new_root);
    printf("\t%p\n", last_of_newroot->data);
    //printf("---last_element of empty_root---\n");
    //t_list *last_of_emptyroot = ft_list_last(empty_root);
    //printf("\t%p\n", (int)last_of_emptyroot->data);

    printf("\n\n");
    ft_list_push_back(root, (void *) 5);
    ft_print_my_linked_list(root);
    ft_list_push_back(new_root, (void *) 5);
    ft_print_my_linked_list(new_root);
    //ft_list_push_back(&empty_root, (void *) 5);
    //ft_print_my_linked_list(&empty_root);

    return 0;
}