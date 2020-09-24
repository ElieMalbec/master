//use ft_putnbr to print a an int
//don't put function in the .h file
#ifndef FT_LIST
#define FT_LIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void    print_my_linked_list(t_list *root){
    t_list *tmp = root;
    int i = 1;
	if (root == NULL) return ;
    while (tmp){
        printf("Node number %d and it's value %p\n", i, tmp->data);
        i++;
        tmp = tmp->next;
    }
}

void    ft_print_my_linked_list(t_list **root){
    t_list **tmp = root;
    int i = 1;

	if (root == NULL || *root == NULL) return ;
    while (*tmp){
        printf("Node number %d and it's value %p\n", i, (*tmp)->data);
        i++;
        tmp = &(*tmp)->next;
    }
}

void    ft_print_my_linked_list_str(t_list **root){
    t_list **tmp = root;
    int i = 1;

    while (*tmp){
        printf("Node number %d and it's value %s\n", i, (*tmp)->data);
        i++;
        tmp = &(*tmp)->next;
    }
}


t_list  *ft_create_elem(void *data){
    t_list *newList;

    if (!(newList = malloc(sizeof(t_list)))){
        return NULL;
    }
    newList->data = data;
    newList->next = NULL;
    return newList;
}

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

int    ft_list_size(t_list *begin_list){
    int size;
    t_list *tmp;

    size = 0;
    tmp = begin_list;
    while (tmp){
        tmp = tmp->next;
        size++;
    }
    return size;
}

t_list *ft_list_last(t_list *begin_list){
    t_list *tmp;

    tmp = begin_list;
    if (tmp == NULL){
        return NULL;
    }
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    return tmp;
}

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

t_list  *ft_list_push_strs(int size, char **strs){
    if ( strs == NULL) return NULL;
    t_list *new_list = ft_create_elem(*strs);
    for (int i = 1; i < size; i++){
        ft_list_push_front(&new_list, strs[i]);
    }
    return new_list;
}

void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *)){
    t_list *tmp;

    while (begin_list){
        tmp = begin_list;
        begin_list = begin_list->next;
        //free_fct(tmp->data);
        free(tmp);
    }
}

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr){
    t_list *tmp;
    unsigned int i;

    i = 1;
    tmp = begin_list;
    while (tmp){
        if (i == nbr){
            return tmp;
        }
        i++;
        tmp = tmp->next;
    }
    tmp = NULL;
    return tmp;
}

void    ft_list_reverse(t_list **begin_list){
    t_list *last = *begin_list;
    t_list *begin = *begin_list;

    while (last->next){
        last = last->next;
    }

    while (begin < last){
        void * tmp = begin->data;
        begin-> data = last->data;
        last->data = tmp;

        begin ++;
        last --;
    }
}

void    ft_list_foreach(t_list *begin_list, void (*f)(void *)){
    while (begin_list){
        f(begin_list->data);
        begin_list = begin_list->next;
    }
}

void    ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)()){
    t_list *tmp = begin_list;

    while (tmp){
        if (cmp(tmp->data, data_ref) == 0){
            f(tmp->data);
        }
        tmp = tmp->next;
    }
}

t_list  *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)()){
    t_list *tmp = begin_list;

    while (tmp){
        if (cmp(tmp->data, data_ref) == 0){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

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
        if (!tmp->next){
            return;
        }
    }
}

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

void	ft_list_reverse_fun2(t_list *begin_list)
{
	t_list	*begin;
	t_list	*end;
	void	*tmp;

	end = 0;
	while (begin_list != end)
	{
		begin = begin_list;
		while (begin->next != end)
		{
			tmp = begin->data;
			begin->data = begin->next->data;
			begin->next->data = tmp;
			begin = begin->next;
		}
		end = begin;
	}
}

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

#endif
