/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** send
*/

#include "tools.h"
#include "server.h"

void send_msg(int socket, char *msg)
{
    printf("\033[1;32msend msg to %d:\033[0m %s", socket, msg);
    if (write(socket, msg, strlen(msg)) < 0)
        printf("Error sending data\n");
}

void send_msg_gui(server_t *server, char *msg)
{
    client_t *tmp = server->client;

    while (tmp != NULL) {
        if (tmp->connected == 2)
            send_msg(tmp->socket, msg);
        tmp = tmp->next;
    }
}
