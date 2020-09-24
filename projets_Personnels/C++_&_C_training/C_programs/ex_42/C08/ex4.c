#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_stock_str {
    int size;
    char *str;
    char *copy;
}   t_stock_str;



struct s_stock_str **ft_strs_to_tab(int ac, char **av){
    t_stock_str **tmp = malloc(sizeof(t_stock_str) * ac);
    
    if (!tmp) return NULL;

    for (int i = 0; i < ac; i++){
        tmp[i] = malloc(sizeof(t_stock_str));
        tmp[i]->size = strlen(av[i]);
        tmp[i]->str = av[i];
        tmp[i]->copy = malloc(sizeof(char *) * tmp[i]->size);
        tmp[i]->copy = strcpy(tmp[i]->copy, av[i]);
    }
    return tmp;
}

void    ft_show_tab(struct s_stock_str **par){
    int i = 0;
    while (par[i]){
        printf("%d %p %s\n", par[i]->size, par[i]->str, par[i]->copy);
        i++;
    }
}

void    ft_show_tab2(struct s_stock_str *par){
    int i = 0;
    while (par[i].str){
        printf("%d %p %s\n", par[i].size, par[i].str, par[i].copy);
        i++;
    }
}

struct s_stock_str *ft_strs_to_tab2(int ac, char **av){
    t_stock_str *tmp;
    int i;

    tmp = malloc(sizeof(t_stock_str) * (ac));
    if (!tmp) return NULL;
    for (i = 0; i < ac; i++){
        tmp[i].size = strlen(av[i]);
        tmp[i].str = av[i];
        tmp[i].copy = malloc(sizeof(char *) * tmp[i].size);
        tmp[i].copy = strcpy(tmp[i].copy, av[i]);
    }
    tmp[i].str = NULL;
    return tmp;
}


int main(void){
    char **arr = malloc(sizeof(*arr) * 3);
    for (int i = 0; i < 3; i++){
        arr[i] = malloc (sizeof(char) * 10);
    }
    arr[0] = "Hello";
    arr[1] = "How";
    arr[2] = "Funny";
        
    t_stock_str **t = ft_strs_to_tab(3, arr);
    t_stock_str *tt = ft_strs_to_tab2(3, arr);

    printf("%p %p %p\n", arr[0], arr[1], arr[2]);
    printf("%d %p %s\n", t[0]->size, t[0]->str, t[0]->copy);
    printf("%d %p %s\n", t[1]->size, t[1]->str, t[1]->copy);
    printf("%d %p %s\n", t[2]->size, t[2]->str, t[2]->copy);
    
    printf("%lu et %lu\n", sizeof(t), sizeof(tt));
    ft_show_tab2(tt);
    printf("-------\n");
    ft_show_tab(t);
    return 0;
}