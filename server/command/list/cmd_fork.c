/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_fork
*/

#include "game.h"

bool check_fork(server_t *server, client_t *c, char *command)
{
    char *str_cmd = NULL;

    if (c->player->incantating || c->player->fork || c->connected != 1) {
        send_msg(c->socket, "ko\n");
        return false;
    }
    str_cmd = calloc(1, sizeof(char) * 100);
    sprintf(str_cmd, "pfk %d\n", c->number);
    pfk_cmd(c, server, str_cmd);
    free(str_cmd);
    c->player->fork = true;
    return true;
}

int get_nb_eggs(game_t *game)
{
    int nb = 0;
    team_t *team = game->teams;

    while (team) {
        nb += team->nb_eggs;
        team = team->next;
    }
    return nb;
}

void fork_cmd(client_t *client, server_t *server, char *str)
{
    team_t *team = find_team_with_name(server->game->teams, client->team);
    char *str_cmd = NULL;

    if (!team) {
        client->player->fork = false;
        return send_msg(client->socket, "ko\n");
    }
    str_cmd = calloc(1, sizeof(char) * 10);
    team->authorized_cli_nb++;
    team->nb_eggs++;
    insert_new_egg_at_end(team, get_nb_eggs(server->game),
    rand() % server->init->width, rand() % server->init->height);
    sprintf(str_cmd, "%d %d\n", client->number, get_nb_eggs(server->game));
    enw_cmd(client, server, str_cmd);
    client->player->fork = false;
    free(str_cmd);
    send_msg(client->socket, "ok\n");
}
