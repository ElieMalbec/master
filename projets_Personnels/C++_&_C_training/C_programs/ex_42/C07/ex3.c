#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int     lenOfWords(char **strs, int size);
char    *ft_strjoin(int size, char **strs, char *sep);
void    add_sep(char *dest, int index, char *sep, int size);
void    concat_words(char *dest, char **strs, int size, char *sep);


/**
 * Calculer la len de chaque mot
 * calculer la len de sep
 * malloc un string size of char* * (size-1*len of sep) + len_words +1(\0)
 */ 
char    *ft_strjoin(int size, char **strs, char *sep){
    if (size == 0){
        return NULL;
    }
    int len_sep = strlen(sep);
    int len_words = lenOfWords(strs, size);

    char * concat_of_words = malloc(sizeof(char) *((size-1) * len_sep) + len_words + 1);
    concat_words(concat_of_words, strs, size, sep);
    return concat_of_words;
}

/*
*   concat words into our dest char. Add a separator between words.
*/
void    concat_words(char *dest, char **strs, int size, char *sep){
    int i = 0;
    int index_dest = 0;

    while (i < size){
        int j = 0;
        while (strs[i][j] != '\0'){
            dest[index_dest] = strs[i][j];
            index_dest++;
            j++;
        }
        if (i != size - 1){
            add_sep(dest, index_dest, sep, strlen(sep));
            index_dest += strlen(sep);
        }
        i++;
    }
    dest[index_dest] = '\0';
}

/**
 * Add a sep between words
*/
void    add_sep(char *dest, int index, char *sep, int size){
    int i = 0;

    while (i < size){
        dest[index] = sep[i];
        index++;
        i++;
    }
}

/*
 * Get the total len of every words in strs
*/
int lenOfWords(char **strs, int size){
    int i = 0;
    int total = 0;
    while (i < size){
        int j = 0;
        while (strs[i][j] != '\0'){
            total++;
            j++;
        }
        i++;
    }
    return total;
}

int main(void){
    char ** strs = malloc(sizeof(char **) * 2);
    for (int i = 0; i < 2; i++){
        strs[i] = malloc(sizeof(char *) * 10);
    }
    strs[0] = strcpy(strs[0], "Hello");
    strs[1] = strcpy(strs[1], "World");

    char * my_string = ft_strjoin(2, strs, "hey");
    printf("%s\n", my_string);

    /*while (*my_string){
        printf("%c", *my_string);
        my_string++;
    }*/
    return 0;
}
