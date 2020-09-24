#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lenOfWords(char *str, char *charset);
int is_charset(char *str, char *charset);
int check_sep(char *str, char *charset, int len_str);
char    **ft_split(char *str, char *charset);

/**
 * Function that replicates strstr but send back an int
 */
int is_charset(char *str, char *charset){
    char * tmp2 = charset;
    if (!charset){
        return -1;
    }

    for ( ; *str != 0; str++){
        if (*str != *tmp2){
            continue;
        }
        char * tmp1 = str;
        while (1){
            if (*tmp2 == 0){
                return 0;
            }
            if (*tmp1++ != *tmp2++){
                break;
            }
        }
        tmp2 = charset;
    }
    return -1;
}

/**
 * Check the number of times there is a separator(charset) in str
 */
int check_sep(char *str, char *charset, int len_str){
    int count = 0;
    for (int i = 0; i < len_str; i++){
        if (*(str+i) == charset[0]){  
            if (is_charset(str+i, charset) == 0){
                count++;
            }
        }
    }
    return count;
}

/***
 * Check number of separator
 * malloc nboFSep+1
 * while i=0 < nbOfSep
 *  malloc size of char len + 1 then strncpy
 * NULL terminate the last one
 */
char    **ft_split(char *str, char *charset){
    int len = strlen(str);
    int nbOfSep = check_sep(str, charset, len) + 1;
    char ** split;
    if (!(split = malloc(sizeof(char **) * (nbOfSep + 1)))){
        return NULL;
    }
    
    int index_split = 0;
    for (int i = 0; i < nbOfSep; i++){
        int len_word = lenOfWords(str+i, charset);
        //printf("len of my word : %d\n", len_word);
        split[index_split] = malloc(sizeof(char) * (len_word + 1));
        strncpy(split[index_split], str+i, len_word);
        index_split++;
        str += len_word + strlen(charset) - 1;//move to first char of the next word
    }
    split[nbOfSep] = '\0';
    return split;
}

/**
 * Function that returns the len of a word
 */
int lenOfWords(char *str, char *charset){
    int len = 0;
    if (!charset){
        return strlen(str);
    }
    for (int i = 0; i < (int) strlen(str); i++){
        if (*(str+i) == charset[0]){  
            if (is_charset(str+i, charset) == 0){
                return len;
            }
        }
        len++;
    }
    return len;
}

#define LEN_OF_WORDS 3
int main(void){
    char * str1 = "HELLOhiMYhiFRIEND";
    char * sep = "hi";
    char ** my_split = ft_split(str1, sep);

    /*
    char **t = malloc(sizeof(char *) * 2);
    for (int i = 0; i < 2; i++){
        t[i] = malloc(sizeof(char) * 12);
    }
    t[0] = strcpy(t[0], "Yeah!");
    t[1] = strcpy(t[1], "Boypohgytii");
    */

    int i = 0;
    if (my_split == NULL) return 0;
    while (i < LEN_OF_WORDS){
        printf("%s\n", my_split[i]);
        i++;
    }
    return 0;
}