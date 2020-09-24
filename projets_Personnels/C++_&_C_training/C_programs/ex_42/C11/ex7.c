#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    ft_swap(char **str1, char **str2){
    char *tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}

//working

void    ft_advanced_sort_string_tab(char **tab, int (*cmp)(char*, char*)){
	int i = 0;
	int j;
	while (tab[i]){
		j = i + 1;
		while (tab[j]){
			if (cmp(tab[i], tab[j]) > 0){
				char *tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			
			}
			j++;
		}
		i++;
	}
}

int cmp(char * str1, char * str2){
    while (*str1 && *str2 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int main(void){
    char **t = malloc(sizeof(char *) * 4);
    for (int i = 0; i < 4; i++){
        t[i] = malloc(sizeof(char) * 12);
    }
	
    t[0] = strcpy(t[0], "Yeah!");
    t[1] = strcpy(t[1], "Boypohgytii");
    t[2] = strcpy(t[2], "Boya");
    t[3] = strcpy(t[3], "AaAh");
    for (int i = 0; i < 4; i++){
        printf("%s\n", t[i]);
    }
    printf("-------\n");
    ft_advanced_sort_string_tab(t, &cmp);
    for (int i = 0; i < 4; i++){
        printf("%s\n", t[i]);
    }
    return 0;
}
