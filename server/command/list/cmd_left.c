/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_left
*/

#include "game.h"

bool check_left(server_t *server, client_t *c, char *command)
{
    if (c->player->incantating || c->player->fork || c->connected != 1) {
        send_msg(c->socket, "ko\n");
        return false;
    }
    return true;
}

void left_cmd(client_t *client, server_t *server, char *str)
{
    char *str_cmd = NULL;

    if (!client || !client->player)
        return;
    if (client->player->direction <= 0)
        client->player->direction = 3;
    else
        client->player->direction--;
    send_msg(client->socket, "ok\n");
    str_cmd = calloc(1, sizeof(char) * 10);
    sprintf(str_cmd, "%d", client->number);
    ppo_cmd(client, server, str_cmd);
    free(str_cmd);
}
