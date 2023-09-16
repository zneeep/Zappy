/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** game
*/

#include "destruct.h"
#include "game.h"

void destroy_players(player_t *player)
{
    if (player == NULL)
        return;
    if (player->next)
        destroy_players(player->next);
    player->next = NULL;
    free(player->rsc);
    free(player);
}

void destroy_player(player_t *player)
{
    if (player == NULL)
        return;
    player->next = NULL;
    free(player->rsc);
    free(player);
}

void destroy_queue(queue_t *queue)
{
    if (!queue)
        return;
    if (queue->next)
        destroy_queue(queue->next);
    free(queue->command);
    free(queue);
}

void game_destroy(server_t *server)
{
    for (int i = 0; i < server->game->map->width; i++)
        free(server->game->map->rsc[i]);
    free(server->game->map->rsc);
    free(server->game->map);
    destroy_teams(server->game->teams);
    destroy_queue(server->queue);
    free(server->game);
}
