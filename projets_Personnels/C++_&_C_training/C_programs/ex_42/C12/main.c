#include "ft_list.h"

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
    printf("-----Pushing back root 5-----\n");
    ft_list_push_back(root, (void *) 5);
    ft_print_my_linked_list(root);
    printf("-----Pushing back new_root 5-----\n");
    ft_list_push_back(new_root, (void *) 5);
    ft_print_my_linked_list(new_root);
    //printf("-----Pushing back empty_root 5\n");
    //ft_list_push_back(&empty_root, (void *) 5);
    //ft_print_my_linked_list(&empty_root);

    printf("\n\n");
    printf("-----ft_list_strs to my_list_of_strs \"Yeah!peur\" & \"boy\"-----\n");
    char **t = malloc(sizeof(char *) * 2);
    for (int i = 0; i < 2; i++){
        t[i] = malloc(sizeof(char) * 12);
    }
    t[0] = strcpy(t[0], "Yeah!peur");
    t[1] = strcpy(t[1], "Boy!");
    //char **tt = NULL;
    t_list *my_list_of_str = ft_list_push_strs(2, t);
    ft_print_my_linked_list_str(&my_list_of_str);

    printf("\n\n");
    printf("-----show n° element of at_root-----\n");
    t_list *at_root = ft_create_elem((void *) 15);
    ft_list_push_back(&at_root, (void *) 16);
    t_list * third = ft_list_at(at_root, (unsigned int) 3);
    t_list * second = ft_list_at(at_root, (unsigned int) 2);
    t_list * first = ft_list_at(at_root, (unsigned int) 1);
    t_list * zero = ft_list_at(at_root, (unsigned int) 0);
    printf("%p\n", third);
    printf("%p\n", second->data);
    printf("%p\n", first->data);
    printf("%p\n", zero);

    printf("\n\n");
    printf("-----print list and print reverse-----\n");
    printf("print list\n");
    print_my_linked_list(at_root);
    ft_list_reverse(&at_root);
    printf("print reverse\n");
    print_my_linked_list(at_root);

    /*
    printf("\n\n");
    printf("-----ft_foreach every elem of a t_list-----\n");
    printf("before\n");
    print_my_linked_list(at_root);
    printf("after\n");
    ft_list_foreach(at_root, &add_one_hundred);
    print_my_linked_list(at_root);
    */

   /*
    printf("\n\n");
    printf("-----ft_foreach if every elem of a t_list-----\n");
    printf("before\n");
    print_my_linked_list(at_root);
    printf("after\n");
    ft_list_foreach_if(at_root, &add_one_hundred);
    print_my_linked_list(at_root);
    */

    /*
    printf("\n\n");
    printf("-----ft_list_find elem of a t_list-----\n");
    printf("%d\n",ft_list_find(at_root, (void *) 15, &strcmp));
    */

    /*
    printf("\n\n");
    printf("-----remove elems of a t_list-----\n");
    ft_list_remove_if(&at_root, (void *) 15, &strcmp, &ft_list_clear);
    print_my_linked_list(at_root);
    */

    printf("\n\n");
    printf("-----merge t_list-----\n");
    //root = NULL;
    //root = malloc(sizeof(t_list **));
    ft_list_merge(root, at_root);
    ft_print_my_linked_list(root);

    /*
    printf("\n\n");
    printf("-----sort t_list-----\n");
    ft_list_sort(root, &strcmp);
    ft_print_my_linked_list(root);
    */

    printf("\n\n");
    printf("-----print list and print reverse-----\n");
    printf("print list\n");
    ft_list_push_back(&at_root, (void *) 17);
    ft_list_push_back(&at_root, (void *) 18);
    print_my_linked_list(at_root);
    ft_list_reverse_fun(at_root);
    ft_list_reverse_fun2(at_root);
    printf("print reverse of reverse\n");
    print_my_linked_list(at_root);

    /*
    printf("\n\n");
    printf("-----insert in sorted list-----\n");
    printf("print list\n");
    print_my_linked_list(at_root);
    ft_sorted_list_insert(&at_root, (void *) 9, &strcmp);
    ft_sorted_list_insert(&at_root, (void *) 9, &strcmp);
    ft_sorted_list_insert(&at_root, (void *) 9, &strcmp);
    ft_sorted_list_insert(&at_root, (void *) 9, &strcmp);
    print_my_linked_list(at_root);
    */

    return 0;
}