/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** look_coords
*/

#include "game.h"

coord_t *get_look_coord_0(game_t *g, player_t *p, int i, int j)
{
    coord_t *co = calloc(1, sizeof(coord_t));

    co->y = (g->map->height + (p->pos_y - i)) % g->map->height;
    co->x = (g->map->width + (p->pos_x - (i - j))) % g->map->width;
    return co;
}

coord_t *get_look_coord_1(game_t *g, player_t *p, int i, int j)
{
    coord_t *co = calloc(1, sizeof(coord_t));

    co->y = (g->map->height + (p->pos_y - (i - j))) % g->map->height;
    co->x = (g->map->width + (p->pos_x + i)) % g->map->width;
    return co;
}

coord_t *get_look_coord_2(game_t *g, player_t *p, int i, int j)
{
    coord_t *co = calloc(1, sizeof(coord_t));

    co->y = (g->map->height + (p->pos_y - i)) % g->map->height;
    co->x = (g->map->width + (p->pos_x + (i - j))) % g->map->width;
    return co;
}

coord_t *get_look_coord_3(game_t *g, player_t *p, int i, int j)
{
    coord_t *co = calloc(1, sizeof(coord_t));

    co->y = (g->map->height + (p->pos_y - (j - i))) % g->map->height;
    co->x = (g->map->width + (p->pos_x - i)) % g->map->width;
    return co;
}
