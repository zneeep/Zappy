/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_level_up
*/

#include "game.h"

int get_tile_nb_players(game_t *game, player_t *p)
{
    team_t *team = game->teams;
    player_t *current = NULL;
    int nb_players = 0;

    while (team) {
        current = team->players;
        while (current) {
            current = find_player_with_co(current, p->pos_x, p->pos_y);
            (current != NULL && current->level == p->level) ? nb_players++ : 0;
            (current != NULL) ? (current = current->next) : 0;
        }
        team = team->next;
    }
    return nb_players;
}

bool check_level_1_4(player_t *player, resources_t rsc, int nb)
{
    if (player->level == 1 && nb >= 1 && rsc.linemate > 0)
        return true;
    if (player->level == 2 && nb >= 2 && rsc.linemate > 0 && rsc.deraumere > 0
    && rsc.sibur > 0)
        return true;
    if (player->level == 3 && nb >= 2 && rsc.linemate > 1 && rsc.sibur > 0
    && rsc.phiras > 1)
        return true;
    if (player->level == 4 && nb >= 4 && rsc.linemate > 0 && rsc.deraumere > 0
    && rsc.sibur > 1 && rsc.phiras > 0)
        return true;
    return false;
}

bool check_level_5_8(player_t *player, resources_t rsc, int nb)
{
    if (player->level == 5 && nb >= 4 && rsc.linemate > 0 && rsc.deraumere > 1
    && rsc.sibur > 0 && rsc.mendiane > 2)
        return true;
    if (player->level == 6 && nb >= 6 && rsc.linemate > 0 && rsc.deraumere > 1
    && rsc.sibur > 2 && rsc.phiras > 0)
        return true;
    if (player->level == 7 && nb >= 6 && rsc.linemate > 1 && rsc.deraumere > 1
    && rsc.sibur > 1 && rsc.mendiane > 1 && rsc.phiras > 1 && rsc.thystame > 0)
        return true;
    return false;
}

bool check_incatation_tile(player_t *player, player_t *p)
{
    player_t *c = player;

    while (c) {
        if (p != c && c->pos_x == p->pos_x && c->pos_y == p->pos_y
        && c->incantating)
            return false;
        c = c->next;
    }
    return true;
}

bool check_level(server_t *server, resources_t rsc, player_t *p)
{
    int nb = get_tile_nb_players(server->game, p);
    if (check_level_1_4(p, rsc, nb))
        return true;
    if (check_level_5_8(p, rsc, nb))
        return true;
    return false;
}
