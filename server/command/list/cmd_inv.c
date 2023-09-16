/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_inv
*/

#include "game.h"

bool check_inv(server_t *server, client_t *c, char *command)
{
    if (c->player->incantating || c->player->fork || c->connected != 1) {
        send_msg(c->socket, "ko\n");
        return false;
    }
    return true;
}

void inv_cmd(client_t *client, server_t *server, char *str)
{
    resources_t *rsc = client->player->rsc;
    char *buf = NULL;
    char *str_cmd = NULL;

    if (!client || !client->player)
        return;
    buf = calloc(1, sizeof(char) * 100);
    sprintf(buf, "[food %d, linemate %d, deraumere %d, sibur %d, mendiane %d, \
phiras %d, thystame %d ]\n", rsc->food, rsc->linemate, rsc->deraumere,
    rsc->sibur, rsc->mendiane, rsc->phiras, rsc->thystame);
    send_msg(client->socket, buf);
    str_cmd = calloc(1, sizeof(char) * 10);
    sprintf(str_cmd, "%d", client->number);
    pin_cmd(client, server, str_cmd);
    if (buf)
        free(buf);
    if (str_cmd)
        free(str_cmd);
}
