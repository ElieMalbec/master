#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

int create_tcp_server(int port, int nb_clients){
    int id_socket;
    struct sockaddr_in sockname;

    //creation socket
    if ((id_socket = socket(PF_INET, SOCK_STREAM, 0)) == -1){
        printf("Error socket\n");
        exit(EXIT_FAILURE);
    }
    //affectation adresse
    sockname.sin_family = AF_INET;
    sockname.sin_port = htons(port);
    sockname.sin_addr.s_addr = inet_addr("127.0.0.1");

    if ((bind(id_socket, (const struct sockaddr *)  &sockname, sizeof(sockname))) == -1){
        printf("Error bind\n");
        exit(EXIT_FAILURE);
    }
    //mise en ecoute
    if ((listen(id_socket, nb_clients)) == -1){
        printf("Error listen\n");
        exit(EXIT_FAILURE);
    }

    return id_socket;
}

int main(void){
    int socket_id = create_tcp_server(60001, 2);
    struct sockaddr_in adresse_client;
    int client_id;
    if ((client_id = accept(socket_id, &adresse_client, 0)) == -1){
        printf("Error accept\n");
        exit(EXIT_FAILURE);
    }
    read(client_id, "hello", 6);
    write(client_id, "hello\n", 6);
    close(socket_id);
    return 0;
}