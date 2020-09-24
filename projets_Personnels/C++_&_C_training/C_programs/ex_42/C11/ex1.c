#include <stdio.h>
#include <stdlib.h>

int *ft_map(int *tab, int length, int (*f)(int)){
    int * new_arr = malloc(sizeof(int) * length);
    if (!new_arr) return NULL;

    for (int i = 0; i < length; i++){
        new_arr[i] = f(tab[i]);
    }
    return new_arr;
}

int plusOne(int x){
    return x + 1;
}

int main(void){
    int t[2] = {0, 1};
    int *test = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++){
        test[i] = 2 + (i * i);
    }

    for (int i = 0; i < 5; i++){
        printf("%d ", test[i]);
    }
    printf("\n");
    test = ft_map(test, 5, &plusOne);
    for (int i = 0; i < 5; i++){
        printf("%d ", test[i]);
    }
    printf("\n");
    int *test2 = ft_map(t, 2, &plusOne);
    for (int i = 0; i < 2; i++){
        printf("%d ", test2[i]);
    }
    printf("\n");
    return 0;
}