/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** receive
*/

#include "destruct.h"

bool read_msg(server_t *server, client_t *client)
{
    char buf[BUF_SIZE];

    memset(buf, 0, BUF_SIZE);
    if (recv(client->socket, buf, BUF_SIZE - 1, 0) <= 0) {
        printf("Connection closed\n");
        disconnect_client(server, client);
        return true;
    }
    for (int i = 0; buf[i]; i++)
        if (buf[i] == '\n' || buf[i] == '\r')
            buf[i] = '\0';
    if (!strcmp(buf, "END"))
        server->stop = true;
    printf("\033[1;36mIncoming %d: %s\n\033[0m", client->socket, buf);
    parse_command(server, client, buf);
    return false;
}

void receive_msg(server_t *server)
{
    bool status = false;
    client_t *client = server->client;

    while (client->next != NULL) {
        if (client->socket > 0 && FD_ISSET(client->socket, &server->readfds))
            status = read_msg(server, client);
        if (status)
            return;
        client = client->next;
    }
    if (client->socket > 0 && FD_ISSET(client->socket, &server->readfds))
        read_msg(server, client);
}
