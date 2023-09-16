/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init
*/

#include "game.h"

void init_game_base_values(game_t *game, init_t *init)
{
    game->frequency = init->frequency;
    game->spawn = 0;
}

bool init_game(server_t *server)
{
    server->game = NULL;
    server->game = calloc(1, sizeof(game_t));
    if (server->game == NULL)
        return false;
    if (!init_map(server->game, server->init))
        return false;
    if (!init_teams(server->game, server->init))
        return false;
    init_game_base_values(server->game, server->init);
    return true;
}
