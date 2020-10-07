#include <stdio.h>

#define DP printf("%s: %d\n", __FILE__, __LINE__)

int main(void){
    DP;
    int a = 8;
    printf("a %d\n", a);
    a= 054;
    printf("a %d\n", a);
    int jours[] = {
        28,29,30,31,32,
        33,34,35,36,37

    };
    printf("jours %ld\n", sizeof(jours));
    int jours2[] = {
        28,29,30,31,32,
        33,34,35,36,37,

    };
    printf("jours %ld\n", sizeof(jours2));

    size_t t = 3.5;
    printf("jours %ld  L:%d %s\n", t, __LINE__, __FILE__);
    FILE * myfile = fopen("myfile", "a+");
    fprintf(myfile, "jours %ld  L:%d %s\n", t, __LINE__, __FILE__);
    fclose(myfile);
    //rename("myfile", "mynewfile");
    return 0;
}