/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** tile_rsc
*/

#include "game.h"

void get_tile_sibur(char **buf, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (!(*buf)) {
            (*buf) = calloc(1, sizeof(char) * 7);
            strcpy((*buf), "sibur");
        } else {
            size_t len = strlen(*buf);
            (*buf) = realloc((*buf), sizeof(char) * (len + 7));
            strcat((*buf), " sibur");
        }
    }
}

void get_tile_thystame(char **buf, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (!(*buf)) {
            (*buf) = calloc(1, sizeof(char) * 10);
            strcpy((*buf), "thystame");
        } else {
            size_t len = strlen(*buf);
            (*buf) = realloc((*buf), sizeof(char) * (len + 10));
            strcat((*buf), " thystame");
        }
    }
}

void add_player_buf(char **buf)
{
    if (!(*buf)) {
        (*buf) = calloc(1, sizeof(char) * 8);
        strcpy((*buf), "player");
    } else {
        size_t len = strlen(*buf);
        (*buf) = realloc((*buf), sizeof(char) * (len + 8));
        strcat((*buf), " player");
    }
}

void get_tile_player(game_t *g, char **buf, int p_y, int p_x)
{
    team_t *team = g->teams;
    player_t *p = NULL;

    while (team) {
        p = team->players;
        while (p) {
            (p->pos_x == p_x && p->pos_y == p_y) ? add_player_buf(buf) : 0;
            p = p->next;
        }
        team = team->next;
    }
}
