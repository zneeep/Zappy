/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** setup_reads
*/

#include "init.h"
#include <math.h>

int timout_select(server_t *server)
{
    float timeout = 1 / server->init->frequency;

    server->timeout.tv_sec = (time_t)timeout;
    server->timeout.tv_usec =\
    (suseconds_t)((timeout - server->timeout.tv_sec) * 1e6);
    return select(server->max_socket + 1, &server->readfds,\
    NULL, NULL, &server->timeout);
}

int setup_server_readfds(server_t *server)
{
    client_t *client = server->client;

    FD_ZERO(&server->readfds);
    FD_SET(server->socket, &server->readfds);
    server->max_socket = server->socket;
    while (client->next) {
        if (client->socket > 0)
            FD_SET(client->socket, &server->readfds);
        if (client->socket > server->max_socket)
            server->max_socket = client->socket;
        client = client->next;
    }
    if (client->socket > 0)
        FD_SET(client->socket, &server->readfds);
    if (client->socket > server->max_socket)
        server->max_socket = client->socket;
    return timout_select(server);
}
