/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_msz
*/

#include "game.h"

bool check_msz(server_t *server, client_t *client, char *command)
{
    if (client->connected != 2)
        return false;
    return true;
}

void msz_cmd(client_t *client, server_t *server, char *str)
{
    char *msg = calloc(1, sizeof(char) * 20);
    int x = server->game->map->width;
    int y = server->game->map->height;

    sprintf(msg, "msz %d %d\n", x, y);
    send_msg(client->socket, msg);
    free(msg);
}
