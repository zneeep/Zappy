/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_take
*/

#include "game.h"

bool check_take(server_t *server, client_t *c, char *command)
{
    if (c->player->incantating || c->player->fork || c->connected != 1) {
        send_msg(c->socket, "ko\n");
        return false;
    }
    return true;
}

void take_cmd(client_t *client, server_t *server, char *str)
{
    char **tab = calloc(1, sizeof(char *) * get_size_tab(str, ' '));
    char *str_cmd = NULL;

    if (!client || !client->player)
        return free(tab);
    if ((tab = get_tab(tab, str, ' ')) == NULL)
        return free_double_ptr(tab);
    if (!ressource_check(client, server->game, tab[1], true)) {
        send_msg(client->socket, "ko\n");
        return free_double_ptr(tab);
    }
    ressource_get(client, server->game, tab[1], true);
    send_msg(client->socket, "ok\n");
    str_cmd = calloc(1, sizeof(char) * 20);
    sprintf(str_cmd, "pgt %d %s\n", client->player->id, tab[1]);
    pgt_cmd(NULL, server, str_cmd);
    free(str_cmd);
    free_double_ptr(tab);
}
