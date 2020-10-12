#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(void){
    int id_socket;
    struct sockaddr_in sockname;
    char s[6] = "";

    if ((id_socket = socket(PF_INET, SOCK_STREAM, 0)) == -1){
        return 1;
    }

    sockname.sin_family = AF_INET;
    sockname.sin_port = htons(60001);
    sockname.sin_addr.s_addr = inet_addr("127.0.0.1");

    /*if ((bind(id_socket, (const struct sockaddr *)  &sockname, sizeof(sockname))) == -1){
        printf("Error bind\n");
        exit(EXIT_FAILURE);
    }*/

    if (connect(id_socket, (const struct sockaddr *) &sockname, sizeof(struct sockaddr_in)) == -1){
        printf("Error connect\n");
        return 1;
    }
    write(id_socket, "Hello\n", 6);
    read(id_socket, s, 6);
    printf("%s", s);
    close(id_socket);
    return 0;
}