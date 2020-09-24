#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_count_if(char **tab, int length, int (*f)(char*)){
    //without using length
    int count = 0;
    (void) length; //to aovid warning
    while (*tab){
        if (f(*tab) != 0){
            count++;
        }
        tab++;
    }
    return count;

    //with length variable
    /*int count = 0;
    int i = 0;

    while (i < length){
        if (f(tab[i])){
            count++;
        }
        i++;
    }
    return count;*/
}

int my_len_inf_to_ten(char *str){
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++){
        size++;
    }
    return (size < 10 ? 1 : 0);
}

int main(void){
    char **t = malloc(sizeof(char *) * 2);
    for (int i = 0; i < 2; i++){
        t[i] = malloc(sizeof(char) * 12);
    }
    t[0] = strcpy(t[0], "Yeah!");
    t[1] = strcpy(t[1], "Boypohgytii");
    printf("%d \n", ft_count_if(t, 2, &my_len_inf_to_ten));
    
    return 0;
}