/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_invoc
*/

#include "game.h"

bool check_invoc(server_t *server, client_t *c, char *command)
{
    resources_t rsc =\
    server->game->map->rsc[c->player->pos_y][c->player->pos_x];
    team_t *team = server->game->teams;

    if (c->player->incantating || c->player->fork || c->connected != 1
    || !check_level(server, rsc, c->player)) {
        send_msg(c->socket, "ko\n");
        return false;
    }

    while (team) {
        if (!check_incatation_tile(team->players, c->player)) {
            send_msg(c->socket, "ko\n");
            return false;
        }
        team = team->next;
    }
    set_player_invoc(server, c->player->pos_x, c->player->pos_y);
    return true;
}

void level_up(game_t *game, player_t *player)
{
    if (player->incantating)
        player->level++;
}

void remove_rsc_2(resources_t rsc, int level)
{
    if (level == 5) {
        rsc.linemate--;
        rsc.deraumere -= 2;
        rsc.sibur--;
        rsc.mendiane -= 3;
    }
    if (level == 6) {
        rsc.linemate--;
        rsc.deraumere -= 2;
        rsc.sibur -= 3;
        rsc.phiras--;
    }
    if (level == 7) {
        rsc.linemate -= 2;
        rsc.deraumere -= 2;
        rsc.sibur -= 2;
        rsc.mendiane -= 2;
        rsc.phiras -= 2;
        rsc.thystame -= 1;
    }
}

void remove_rsc(resources_t rsc, int level)
{
    if (level == 1)
        rsc.linemate--;
    if (level == 2) {
        rsc.linemate--;
        rsc.deraumere--;
        rsc.sibur--;
    }
    if (level == 3) {
        rsc.linemate -= 2;
        rsc.sibur--;
        rsc.phiras -= 2;
    }
    if (level == 4) {
        rsc.linemate--;
        rsc.deraumere--;
        rsc.sibur -= 2;
        rsc.phiras--;
    }
    remove_rsc_2(rsc, level);
}

void invoc_cmd(client_t *client, server_t *server, char *str)
{
    char *buf = NULL;
    char *str_cmd = NULL;
    int x = client->player->pos_x;
    int y = client->player->pos_y;
    resources_t rsc = server->game->map->rsc[y][x];

    if (!check_level(server, rsc, client->player))
        return remove_player_invoc(server, x, y, "ko\n");
    buf = calloc(1, sizeof(char) * 25);
    sprintf(buf, "Current level:%d\n", ++client->player->level);
    action_on_tile(client, server->game, level_up);
    remove_player_invoc(server, x, y, buf);
    remove_rsc(rsc, client->player->level);
    str_cmd = calloc(1, sizeof(char) * 20);
    sprintf(str_cmd, "pie %d %d\n", client->player->id, 0);
    pie_cmd(client, server, str_cmd);
    free(buf);
    free(str_cmd);
}
