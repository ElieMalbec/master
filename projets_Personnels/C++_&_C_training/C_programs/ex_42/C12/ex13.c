#include "ft_list.h"

void    ft_list_merge(t_list **begin_list1, t_list *begin_list2){
    /*if (begin_list1 == NULL){
        begin_list1 = malloc(sizeof(t_list **));
        *begin_list1 = begin_list2;
        return ;
    }*/

    if (begin_list1 != NULL && *begin_list1 == NULL){
        *begin_list1 = begin_list2;
        return ;
    }

    t_list *tmp = *begin_list1;
    while (tmp->next){
        tmp = tmp->next;
    }
    tmp->next = begin_list2;
}

