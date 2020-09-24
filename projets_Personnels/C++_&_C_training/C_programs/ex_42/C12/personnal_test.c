#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  s_list {
    int data;
    struct s_list *next;
}   t_list;

void    print_my_linked_list(t_list *root);
void    ft_sorted_list_insert(t_list **begin_list, int data, int (*cmp)(int, int));
void    ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)(int, int));
t_list  *ft_create_elem(int data);
int compa(int x, int y);
void    ft_list_sort(t_list **begin_list, int (*cmp)(int, int));

int compa(int x, int y){
    return (x > y ? 1 :  x == y ? 0 : -1);
}

void    ft_sorted_list_insert(t_list **begin_list, int data, int (*cmp)(int, int)){
    if (!*begin_list){
        *begin_list = ft_create_elem(data);
        return ;
    }

    if (cmp((*begin_list)->data, data) > 0){
        //create elem and then swap it
        t_list *root = *begin_list;
        *begin_list = ft_create_elem(data);
        (*begin_list)->next = root;
        return ;
    }

    t_list *tmp = *begin_list;
    t_list *next = tmp->next;
    while (next && (cmp(next->data, data) <= 0)){
        tmp = next;
        next = tmp->next;
    }
    tmp->next = ft_create_elem(data);
    tmp->next->next = next;
}

void    ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)(int, int)){
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

t_list  *ft_create_elem(int data){
    t_list *newList;

    if (!(newList = malloc(sizeof(t_list)))){
        return NULL;
    }
    newList->data = data;
    newList->next = NULL;
    return newList;
}

void    print_my_linked_list(t_list *root){
    t_list *tmp = root;
    int i = 1;
	if (root == NULL) return ;
    while (tmp){
        printf("Node number %d and it's value %d\n", i, tmp->data);
        i++;
        tmp = tmp->next;
    }
}

void    ft_list_sort(t_list **begin_list, int (*cmp)(int, int)){
    t_list *tmp = *begin_list;

    if (*begin_list == NULL || (*begin_list)->next == NULL) return ;
    while (tmp){
        t_list *tmp2 = tmp;
        while (tmp2 && tmp2->next && cmp(tmp2->data, tmp2->next->data) > 0){
            int temp = tmp2->data;
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

int main(void){
    t_list *root = ft_create_elem(5);
    root->next = ft_create_elem(12);
    root->next->next = ft_create_elem(15);

    t_list *l2 = ft_create_elem(2);
    l2->next = ft_create_elem(25);
    l2->next->next = ft_create_elem(16);
    print_my_linked_list(root);
    printf("\n");
    print_my_linked_list(l2);
    printf("\n");
    ft_list_sort(&l2, &compa);
    print_my_linked_list(l2);

    /*
    printf("\n -----\n");
    ft_sorted_list_insert(&root, 4, &compa);
    print_my_linked_list(root);

    printf("\n -----\n");
    ft_sorted_list_merge(&root, l2, &compa);
    print_my_linked_list(root);
    */
    return 0;
}