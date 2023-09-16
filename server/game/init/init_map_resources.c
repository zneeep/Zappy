/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init_map_2
*/

#include "game.h"

void init_resource_cell(game_t *game, const char *type, int qty)
{
    for (int i = 0; i < qty; i++) {
        int rand_x = rand() % game->map->width;
        int rand_y = rand() % game->map->height;
        game->map->rsc[rand_y][rand_x] =
        modif_resources_cell(game->map->rsc[rand_y][rand_x], type, 1);
    }
}

void init_resources_map(game_t *game)
{
    srand(time(NULL));
    init_resource_cell(game, "food"
    , game->map->width * game->map->height * 0.5);
    init_resource_cell(game, "linemate"
    , game->map->width * game->map->height * 0.3);
    init_resource_cell(game, "deraumere"
    , game->map->width * game->map->height * 0.15);
    init_resource_cell(game, "sibur"
    , game->map->width * game->map->height * 0.1);
    init_resource_cell(game, "mendiane"
    , game->map->width * game->map->height * 0.1);
    init_resource_cell(game, "phiras"
    , game->map->width * game->map->height * 0.08);
    init_resource_cell(game, "thystame"
    , game->map->width * game->map->height * 0.05);
}
