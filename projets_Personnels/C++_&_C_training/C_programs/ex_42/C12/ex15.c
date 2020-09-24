#include "ft_list.h"

void    ft_list_reverse_fun(t_list *begin_list){
    if (!begin_list) return ;

    t_list *last = begin_list;
    while (last->next){
        last = last->next;
    }

    t_list *debut = begin_list;
    while (debut < last){
        void * temp = debut->data;
        debut->data = last->data;
        last->data = temp;

        debut++;
        last--;
    }
}

