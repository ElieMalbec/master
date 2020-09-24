#include <stdlib.h>
#include <stdio.h>


/**
 * Calculer la len de chaque mot
 * calculer la len de sep
 * malloc un string size of char * * size + len_words +1(\0)
 */ 
char    *ft_strjoin(int size, char **strs, char *sep){

}

int main(void){
    char ** strs = malloc(sizeof(char **) * 2);
    for (int i = 0; i < 2; i++){
        strs[i] = malloc(sizeof(char *) * 10);
    }
    strs[0] = strcpy(strs[0], "Yeah");
    strs[0] = strcpy(strs[0], "LOL");

    char * my_string= ft_strjoin(2, strs, "hi");
    printf("%s\n", my_string);
    return 0;
}