#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_any(char **tab, int (*f)(char *)){
	char ** tmp = tab;

	while (*tmp != NULL){
        if (f(*tmp) != 0){
            return 1;
        }
		tmp++;
	}
    return 0;
}

int my_len_inf_to_ten(char *str){
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++){
        size++;
    }
    return (size < 10 ? 0 : 1);
}

int main(void){
    //char *test[2] = {"Hello", "coco"};
    //char *test2[2] = {"anticonstitutionnellement", "Boris"};
    //char *test3[2] = {"sony", "sony_mega_hyper_drive"};

    char **t = malloc(sizeof(char *) * 2);
    for (int i = 0; i < 2; i++){
        t[i] = malloc(sizeof(char) * 12);
    }
    t[0] = strcpy(t[0], "Yeah!peur");
    t[1] = strcpy(t[1], "Boy!");
    printf("%d \n", ft_any(t, &my_len_inf_to_ten));
    //printf("%d \n", ft_any(test, &my_len_inf_to_ten));
    //printf("%d \n", ft_any(test2, &my_len_inf_to_ten));
    //printf("%d \n", ft_any(test3, &my_len_inf_to_ten));
    return 0;
}
