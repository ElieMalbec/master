#include "ft_list.h"

void    ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)()){
    if (!*begin_list){
        *begin_list = ft_create_elem(data);
        return ;
    }

    if ((*begin_list)->next == NULL){
        if (cmp((*begin_list)->data, data) > 0){
            //create elem and then swap it
            (*begin_list)->next = ft_create_elem(data);
            void * temp = (*begin_list)->data;
            (*begin_list)->data = (*begin_list)->next->data;
            (*begin_list)->next->data = temp;
        }
        else {
            //just create it at then end
            (*begin_list)->next = ft_create_elem(data);
        }
        return ;
    }

    t_list *tmp = *begin_list;
    while (tmp->next){
        if (cmp(tmp->data, data) > 0){
            *begin_list = ft_create_elem(data);
            (*begin_list)->next = tmp;
            return ;
        }
        while (tmp && tmp->next && cmp(tmp->next->data, data) <= 0){
            tmp = tmp->next;
        }
        t_list * follow_up = tmp->next;
        tmp->next = ft_create_elem(data);
        tmp->next->next = follow_up;
    }
}