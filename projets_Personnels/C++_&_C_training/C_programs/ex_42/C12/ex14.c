#include "ft_list.h"

void    ft_list_sort(t_list **begin_list, int (*cmp)()){
    t_list *tmp = *begin_list;

    if (*begin_list == NULL || (*begin_list)->next == NULL) return ;
    while (tmp){
        t_list *tmp2 = tmp;
        while (tmp2 && tmp2->next && cmp(tmp2->data, tmp2->next->data) > 0){
            void * temp = tmp2->data;
            tmp2->data = tmp2->next->data;
            tmp2->next->data = temp;
            tmp2 = tmp2->next;
        }
        if (tmp && tmp->next && cmp(tmp->data, tmp->next->data) <= 0){
            tmp = tmp->next;
        }
        
    }
}