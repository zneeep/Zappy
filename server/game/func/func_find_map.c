/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** func_find_map
*/

#include "game.h"

player_t *find_player_with_co(player_t *player, int x, int y)
{
    player_t *current = player;

    while (current) {
        if (current->pos_x == x && current->pos_y == y)
            return current;
        current = current->next;
    }
    return NULL;
}

void action_on_tile(client_t *client, game_t *game, func_t function)
{
    team_t *team = game->teams;
    player_t *current = NULL;
    int x = client->player->pos_x;
    int y = client->player->pos_y;

    while (team) {
        current = team->players;
        while (current) {
            current = find_player_with_co(current, x, y);
            (current != NULL && current != client->player) ?\
            function(game, current) : 0;
            (current != NULL) ? (current = current->next) : 0;
        }
        team = team->next;
    }
}
