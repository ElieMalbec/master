#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    ft_swap(char **str1, char **str2){
    char *tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}

/*
//not working
void    ft_sort_string_tab(char **tab){
    char **run = tab;

    while (*run){
        if (strcmp(*(char **)run, *(char **)run+1) > 0){
            //ft_swap(&(*run), &(*(run+1)));
            char *tmp = *run;
            *run = *run+1;
            *(run+1) = tmp;
            run = tab;
        }
        else {
            run++;
        }
    }
}*/


//not working
void    ft_sort_string_tab(char **tab){
    char **run = tab;

    while (*run){
        char * next = *(run+1); 
        while (*next){
            if (strcmp(*run, next) > 0){
                //ft_swap(&(*run), &(*(run+1)));
                char *tmp = *run;
                *run = *run+1;
                *(run+1) = tmp;
            }
            next++;
        }
        run++;
    }
}


//working
/*
void    ft_sort_string_tab(char **tab){
	int i = 0;
	int j;
	while (tab[i]){
		j = i + 1;
		while (tab[j]){
			if (strcmp(tab[i], tab[j]) > 0){
				char *tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			
			}
			j++;
		}
		i++;
	}
}*/


/*
//not working
void    ft_sort_string_tab(char **tab){
	int i = 0;
	while (tab[i]){
		if (strcmp(tab[i], tab[i+1]) > 0){
			char *tmp = tab[i];
			tab[i] = tab[i+1];
			tab[i+1] = tmp;
            i = -1;
		}
		i++;
	}
}
*/

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
	/*printf("%d\n", strcmp(t[0], t[1]));
    char ** tmp = t;
    char * temp = *t;
    *t = *t+1;
    *(t+1) = temp;
    printf("%d\n", strcmp(t[0], t[1]));
    for (int i = 0; i < 4; i++){
        printf("%s\n", t[i]);
    }
    */
    //printf("size %d, %d -------\n", sizeof(t), sizeof(t)/sizeof(*t));
    printf("-------\n");
    ft_sort_string_tab(t);
    for (int i = 0; i < 4; i++){
        printf("%s\n", t[i]);
    }
    return 0;
}
