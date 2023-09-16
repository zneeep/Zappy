/*
** EPITECH PROJECT, 2023
** myteams
** File description:
** init_server
*/

#include "init.h"

int bind_socket(server_t *server)
{
    socklen_t size = sizeof(server->addr);

    if (bind(server->socket, (struct sockaddr *)&server->addr, size) == -1) {
        perror("bind");
        return false;
    }
    if (listen(server->socket, QUEUE_LENGTH) == -1) {
        perror("listen");
        return false;
    }
    return true;
}

void conf_server_addr(server_t *server, int port)
{
    memset(&server->addr, 0, sizeof(server->addr));
    server->addr.sin_family = AF_INET;
    server->addr.sin_port = htons(port);
    server->addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

bool create_server_socket(server_t *server, int port)
{
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket == -1) {
        perror("socket");
        return false;
    }
    conf_server_addr(server, port);
    if (!bind_socket(server))
        return false;
    server->addrlen = sizeof(server->clientaddr);
    return true;
}

bool init_server(server_t *server, int port)
{
    if (!server) {
        printf("ERROR, server not in initialized\n");
        return false;
    }
    if (!create_server_socket(server, port)) {
        printf("ERROR, can't init server\n");
        return false;
    }
    printf("Server listening on port %d\n", port);
    server->client_num = 0;
    server->nb_clients = 0;
    server->stop = false;
    server->start = false;
    server->queue = NULL;
    return true;
}
