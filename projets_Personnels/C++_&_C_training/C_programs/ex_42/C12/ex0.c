#include "ft_list.h"

/*t_list  *ft_create_elem(void *data){
    t_list *newList;

    if (!(newList = malloc(sizeof(t_list)))){
        return NULL;
    }
    newList->data = data;
    newList->next = NULL;
    return newList;
}*/

/*void    print_my_linked_list(t_list *root){
    t_list *tmp = root;
    int i = 1;

    while (tmp){
        printf("Node number %d and it's value %d\n", i, tmp->data);
        i++;
        tmp = tmp->next;
    }
}*/

int main(){
    int a = 5;
    int b = 12;
    //int *a_ptr = &a;
    //int *b_ptr = &b;
    t_list *my_linked_list = ft_create_elem((void *) a);
    my_linked_list->next = ft_create_elem((void *) b);
    print_my_linked_list(my_linked_list);
    return 0;
}