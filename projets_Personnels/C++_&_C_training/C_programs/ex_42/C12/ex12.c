#include "ft_list.h"


void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *)){
    t_list *tmp = *begin_list;
    t_list * prev;

    while (tmp && cmp(tmp->data, data_ref) == 0){
        *begin_list = tmp->next;
        free_fct(tmp->data);
        free(tmp);
        tmp = *begin_list;
    }

    while (tmp){
        //while everything is ok
        while (tmp && cmp(tmp->data, data_ref) != 0){
            prev = tmp;
            tmp = tmp->next;
        }

        //if tmp is null, we quit
        if (!tmp){
            return ;
        }

        //no need to compare again because we know cpm = 0
        //if (cmp(tmp->data, data_ref) == 0)
        prev->next = tmp->next;
        free_fct(tmp->data);
        free(tmp);
        tmp = prev->next;
    }
}

