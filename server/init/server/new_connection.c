/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** new_connection
*/

#include "init.h"

void add_client(server_t *server, int socket)
{
    client_t *client = server->client;

    while (client) {
        if (client->socket == 0) {
            client->socket = socket;
            return;
        }
        client = client->next;
    }
    init_client(server, socket);
}

void add_connection_to_list(server_t *server, int new_socket)
{
    int port = ntohs(server->clientaddr.sin_port);

    add_client(server, new_socket);
    printf("Client connected: ");
    printf("%s:%d\n", inet_ntoa(server->clientaddr.sin_addr), port);
    send_msg(new_socket, "WELCOME\n");
}

void check_new_connection(server_t *server, int new_socket)
{
    client_t *client = server->client;

    while (client->next) {
        if (client->socket == new_socket)
            return;
        else
            client = client->next;
    }
    add_connection_to_list(server, new_socket);
    server->nb_clients++;
}

void new_connection(server_t *server)
{
    int new_socket = 0;

    if (FD_ISSET(server->socket, &server->readfds)) {
        if ((new_socket = accept(server->socket,\
        (struct sockaddr *)&server->clientaddr, &server->addrlen)) < 0) {
            perror("accept");
            return;
        }
        check_new_connection(server, new_socket);
    }
}
