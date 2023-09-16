/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** rsc_management
*/

#include "game.h"

void ressource_manager(int *rsc_player, int *rsc_map, bool add)
{
    if (add) {
        if ((*rsc_map) > 0) {
            (*rsc_player)++;
            (*rsc_map)--;
        }
    } else {
        if ((*rsc_player) > 0) {
            (*rsc_player)--;
            (*rsc_map)++;
        }
    }
}

void get_new_life(client_t *client, bool add)
{
    if (add) {
        client->player->life += 126;
    } else {
        client->player->life -= 126;
    }
}

bool ressource_check_2(int rsc_map, int rsc_player, bool add)
{
    if (add) {
        if (rsc_map > 0)
            return true;
        return false;
    } else {
        if (rsc_player > 0)
            return true;
        return false;
    }
    return false;
}

bool ressource_check(client_t *client, game_t *game, char *name, bool add)
{
    resources_t *rsc_p = client->player->rsc;
    resources_t rsc_map =\
    game->map->rsc[client->player->pos_y][client->player->pos_x];

    if (!strcmp(name, "food"))
        return ressource_check_2(rsc_map.food, rsc_p->food, add);
    if (!strcmp(name, "linemate"))
        return ressource_check_2(rsc_map.linemate, rsc_p->linemate, add);
    if (!strcmp(name, "deraumere"))
        return ressource_check_2(rsc_map.deraumere, rsc_p->deraumere, add);
    if (!strcmp(name, "sibur"))
        return ressource_check_2(rsc_map.sibur, rsc_p->sibur, add);
    if (!strcmp(name, "mendiane"))
        return ressource_check_2(rsc_map.mendiane, rsc_p->mendiane, add);
    if (!strcmp(name, "phiras"))
        return ressource_check_2(rsc_map.phiras, rsc_p->phiras, add);
    if (!strcmp(name, "thystame"))
        return ressource_check_2(rsc_map.thystame, rsc_p->thystame, add);
    return false;
}

void ressource_get(client_t *client, game_t *game, char *name, bool add)
{
    int x = client->player->pos_x;
    int y = client->player->pos_y;

    (!strcmp(name, "food")) ? get_new_life(client, add) : 0;
    (!strcmp(name, "food")) ? ressource_manager(\
    &client->player->rsc->food, &game->map->rsc[y][x].food, add) : 0;
    (!strcmp(name, "linemate")) ? ressource_manager(\
    &client->player->rsc->linemate, &game->map->rsc[y][x].linemate, add) : 0;
    (!strcmp(name, "deraumere")) ? ressource_manager(\
    &client->player->rsc->deraumere, &game->map->rsc[y][x].deraumere, add) : 0;
    (!strcmp(name, "sibur")) ? ressource_manager(\
    &client->player->rsc->sibur, &game->map->rsc[y][x].sibur, add) : 0;
    (!strcmp(name, "mendiane")) ? ressource_manager(\
    &client->player->rsc->mendiane, &game->map->rsc[y][x].mendiane, add) : 0;
    (!strcmp(name, "phiras")) ? ressource_manager(\
    &client->player->rsc->phiras, &game->map->rsc[y][x].phiras, add) : 0;
    (!strcmp(name, "thystame")) ? ressource_manager(\
    &client->player->rsc->thystame, &game->map->rsc[y][x].thystame, add) : 0;
}
