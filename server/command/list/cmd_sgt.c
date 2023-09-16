/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_sgt
*/

#include "game.h"

bool check_sgt(server_t *server, client_t *client, char *command)
{
    if (client->connected != 2)
        return false;
    return true;
}

void sgt_cmd(client_t *client, server_t *server, char *str)
{
    char *msg = calloc(1, sizeof(char) * 20);
    int value = server->init->frequency;

    sprintf(msg, "sgt %d\n", value);
    send_msg(client->socket, msg);
    free(msg);
}
