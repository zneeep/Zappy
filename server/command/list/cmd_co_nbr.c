/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_co_nbr
*/

#include "game.h"

bool check_co_nbr(server_t *server, client_t *c, char *command)
{
    if (c->player->incantating || c->player->fork || c->connected != 1) {
        send_msg(c->socket, "ko\n");
        return false;
    }
    return true;
}

void co_nbr_cmd(server_t *server, int socket)
{
    client_t *client = NULL;
    team_t *team = NULL;
    char *buf = NULL;
    int nb = 0;

    if (!(client = find_client_from_socket(server, socket)))
        return;
    if (!(team = find_team_with_name(server->game->teams, client->team)))
        return;
    nb = team->authorized_cli_nb - team->nb_clients;
    buf = calloc(1, sizeof(char) * 4);
    sprintf(buf, "%d\n", nb);
    send_msg(socket, buf);
    free(buf);
}
