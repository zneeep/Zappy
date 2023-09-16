/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init_map
*/

#include "game.h"

resources_t declare_resources_map(resources_t rsc)
{
    rsc.food = 0;
    rsc.linemate = 0;
    rsc.deraumere = 0;
    rsc.sibur = 0;
    rsc.mendiane = 0;
    rsc.phiras = 0;
    rsc.thystame = 0;
    return rsc;
}

void create_map(game_t *game)
{
    game->map->rsc = NULL;
    game->map->rsc = calloc(1, sizeof(resources_t *) * game->map->height);
    if (game->map->rsc == NULL)
        return;
    for (int i = 0; i < game->map->width; i++) {
        game->map->rsc[i] = NULL;
        game->map->rsc[i] = calloc(1, sizeof(resources_t) * game->map->width);
        if (game->map->rsc[i] == NULL)
            return;
    }
    for (int i = 0; i < game->map->height; i++) {
        for (int j = 0; j < game->map->width; j++) {
            game->map->rsc[i][j] = declare_resources_map(game->map->rsc[i][j]);
        }
    }
}

bool init_map(game_t *game, init_t *init)
{
    game->map = NULL;
    game->map = calloc(1, sizeof(map_t));
    if (game->map == NULL) {
        perror("map");
        return false;
    }
    game->map->width = init->width;
    game->map->height = init->height;
    create_map(game);
    init_resources_map(game);
    return true;
}
