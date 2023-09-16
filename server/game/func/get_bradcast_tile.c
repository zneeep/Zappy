/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** get_bradcast_tile
*/

#include "game.h"

coord_t *get_vector(player_t *source, player_t *dest, int height, int width)
{
    coord_t *vector = calloc(1, sizeof(coord_t));
    int dx = source->pos_x - dest->pos_x;
    int dy = source->pos_y - dest->pos_y;

    if (dx > width / 2)
        dx -= width;
    else if (dx < -width / 2)
        dx += width;
    if (dy > height / 2)
        dy -= height;
    else if (dy < -height / 2)
        dy += height;
    vector->x = dx;
    vector->y = dy;
    return vector;
}

int get_tile_from_co(coord_t *vector)
{
    if (vector->x == 0) {
        if (vector->y > 0)
            return 5;
        if (vector->y < 0)
            return 1;
    }
    if (vector->y == 0) {
        if (vector->x > 0)
            return 7;
        if (vector->x < 0)
            return 3;
    }
    if (vector->x > 0 && vector->y > 0)
        return 6;
    if (vector->x < 0 && vector->y < 0)
        return 2;
    if (vector->x < 0 && vector->y > 0)
        return 4;
    if (vector->x > 0 && vector->y < 0)
        return 8;
    return 0;
}
