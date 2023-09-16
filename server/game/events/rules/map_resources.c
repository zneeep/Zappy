/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** map_resources
*/

#include "game.h"

void find_quantity_rsc_bis(map_t *map, resources_t *rsc, int i)
{
    for (int j = 0; j < map->width; j++) {
        rsc->food += map->rsc[i][j].food;
        rsc->linemate += map->rsc[i][j].linemate;
        rsc->deraumere += map->rsc[i][j].deraumere;
        rsc->sibur += map->rsc[i][j].sibur;
        rsc->mendiane += map->rsc[i][j].mendiane;
        rsc->phiras += map->rsc[i][j].phiras;
        rsc->thystame += map->rsc[i][j].thystame;
    }
}

void find_quantity_rsc(map_t *map, resources_t *rsc)
{
    for (int i = 0; i < map->height; i++)
        find_quantity_rsc_bis(map, rsc, i);
}

void init_rsc_management(resources_t *rsc)
{
    rsc->food = 0;
    rsc->linemate = 0;
    rsc->deraumere = 0;
    rsc->sibur = 0;
    rsc->mendiane = 0;
    rsc->phiras = 0;
    rsc->thystame = 0;
}

void resources_management(game_t *game, resources_t *rsc)
{
    int freq = game->map->width * game->map->height;

    if (rsc->food < (freq * 0.5))
        init_resource_cell(game, "food", (freq * 0.5) - rsc->food);
    if (rsc->linemate < (freq * 0.3))
        init_resource_cell(game, "linemate", (freq * 0.3) - rsc->linemate);
    if (rsc->deraumere < (freq * 0.15))
        init_resource_cell(game, "deraumere", (freq * 0.15) - rsc->deraumere);
    if (rsc->sibur < (freq * 0.1))
        init_resource_cell(game, "sibur", (freq * 0.1) - rsc->sibur);
    if (rsc->mendiane < (freq * 0.1))
        init_resource_cell(game, "mendiane", (freq * 0.1) - rsc->mendiane);
    if (rsc->phiras < (freq * 0.08))
        init_resource_cell(game, "phiras", (freq * 0.08) - rsc->phiras);
    if (rsc->thystame < (freq * 0.05))
        init_resource_cell(game, "thystame", (freq * 0.05) - rsc->thystame);
}

void map_resources_management(game_t *game)
{
    resources_t *rsc = NULL;

    if (!(rsc = calloc(1, sizeof(resources_t))))
        return;
    init_rsc_management(rsc);
    find_quantity_rsc(game->map, rsc);
    resources_management(game, rsc);
    free(rsc);
}
