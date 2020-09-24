#include <stdio.h>

int ft_is_sort(int *tab, int length, int (*f)(int, int)){
    int i = 0;

    while (i < length - 1){
        if (f(tab[i], tab[i + 1]) > 0){
            return 0;
        }
        i++;
    }
    return 1;
}

int is_inf(int x, int y){
    return (x < y ? -1 : x == y ? 0 : 1);
}

int main(void){
    int arr[] = {1,2,3,4,5,6,7};
    int arr2[] = {5,8,7};
    int arr3[] = {};
    int arr4[] = {1,2,3,4,5,6,7,5};

    printf("%d \n", ft_is_sort(arr, 7, &is_inf));
    printf("%d \n", ft_is_sort(arr2, 3, &is_inf));
    printf("%d \n", ft_is_sort(arr3, 0, &is_inf));
    printf("%d \n", ft_is_sort(arr4, 88, &is_inf));
    return 0;
}