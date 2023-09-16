/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_tna
*/

#include "game.h"

bool check_tna(server_t *server, client_t *client, char *command)
{
    if (client->connected != 2)
        return false;
    return true;
}

void tna_cmd(client_t *client, server_t *server, char *idk)
{
    team_t *team = server->game->teams;

    while (team != NULL) {
        char *msg = NULL;
        msg = calloc(1, sizeof(char) * 64);
        sprintf(msg, "tna %s\n", team->name);
        send_msg_gui(server, msg);
        free(msg);
        team = team->next;
    }
}
