/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_eject
*/

#include "game.h"

bool check_eject(server_t *server, client_t *c, char *command)
{
    if (c->player->incantating || c->player->fork || c->connected != 1) {
        send_msg(c->socket, "ko\n");
        return false;
    }
    return true;
}

void eject_cmd(client_t *client, server_t *server, char *str)
{
    char *str_cmd = NULL;

    action_on_egg(server, client, server->game);
    switch (client->player->direction) {
        case 0:
            action_on_tile(client, server->game, eject_player_0);
        case 1:
            action_on_tile(client, server->game, eject_player_1);
        case 2:
            action_on_tile(client, server->game, eject_player_2);
        case 3:
            action_on_tile(client, server->game, eject_player_3);
        default:
            break;
    }
    send_msg(client->socket, "ok\n");
    str_cmd = calloc(1, sizeof(char) * 10);
    sprintf(str_cmd, "pex %d\n", client->number);
    pex_cmd(client, server, str_cmd);
    free(str_cmd);
}
