#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv){
    if (argc == 1){
        char *message = "File name missing.";
        write(0, message, strlen(message));
        write(0, "\n", 1);
        return 0 ;
    }
    else if (argc != 2){
        char *message = "Too many arguments.";
        write(0, message, strlen(message));
        write(0, "\n", 1);
        return 0;
    }
    int file = open(argv[1], O_RDONLY);
    if (file < 0){
        char *message = "Cannot read file.";
        write(0, message, strlen(message));
        write(0, "\n", 1);
        return 0;
    }
    
   char c;
    while (read(file, &c, 1)){
        write(1, &c, 1);
    }
    close(file);
    return 0;
}

