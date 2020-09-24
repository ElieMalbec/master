#include "ft_list.h"

void    ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)()){
    //check si begin_list1 & 2 sont par ordre croissant
    if (!*begin_list1){
        *begin_list1 = begin_list2;
        return ;
    }
    if (!begin_list2){
        return ;
    }

    t_list *tmp1 = *begin_list1;
    t_list *tmp2 = begin_list2;

    if (cmp(tmp1->data, tmp2->data) > 0){
        //if L2 < L1, add at the beginning of L1 the node L2
        t_list *newNode = ft_create_elem(tmp2->data);
        newNode->next = tmp1;
        *begin_list1 = newNode;
        tmp2 = tmp2->next;
        tmp1 = *begin_list1;
    }
    while (tmp1->next){
        if (!tmp2) tmp1 = tmp1->next;
        else if (cmp(tmp1->next->data, tmp2->data) <= 0){
            tmp1 = tmp1->next;
        }
        else if (cmp(tmp1->next->data, tmp2->data) > 0){
            t_list *newNode = ft_create_elem(tmp2->data);
            newNode->next = tmp1->next;
            tmp1->next = newNode;
            tmp2 = tmp2->next;
        }
    }
    tmp1->next = tmp2;
}