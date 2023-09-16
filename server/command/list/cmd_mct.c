/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_mct
*/

#include "game.h"

bool check_mct(server_t *server, client_t *client, char *command)
{
    if (client->connected != 2)
        return false;
    return true;
}

void mct_cmd(client_t *client, server_t *server, char *str)
{
    for (int x = 0; x < server->game->map->height; x++)
        for (int y = 0; y < server->game->map->height; y++)
            bct_bis_cmd(client->socket, server->game, x, y);
}
