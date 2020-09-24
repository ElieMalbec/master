#include <unistd.h>
#include <string.h>

void    print_args(char **argv, int size){
    int i = 1;

    while (i != size){
        write(0, argv[i], strlen(argv[i]));
        write(0, "\n", 1);
        i++;
    } 
}

void    sort_args(char **argv, int argc){
    int i = 1;
    while (i < argc - 1){
        if (strcmp(argv[i], argv[i+1]) > 0){
            char * tmp = argv[i];
            argv[i] = argv[i+1];
            argv[i+1] = tmp;
            i = 0;
        }
        i++;
    }
}

int main(int argc, char **argv){
    if (argc == 1) return 0;
    sort_args(argv, argc);
    print_args(argv, argc);
    return 0;
}