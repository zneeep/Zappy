/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_eject_2
*/

#include "game.h"

void eject_player_0(game_t *game, player_t *player)
{
    player->ejected = true;
    if (player->pos_y <= 0)
        player->pos_y = (game->map->height - 1);
    else
        player->pos_y--;
}

void eject_player_1(game_t *game, player_t *player)
{
    player->ejected = true;
    if (player->pos_x >= game->map->width)
        player->pos_x = 0;
    else
        player->pos_x++;
}

void eject_player_2(game_t *game, player_t *player)
{
    player->ejected = true;
    if (player->pos_y >= game->map->height)
        player->pos_y = 0;
    else
        player->pos_y++;
}

void eject_player_3(game_t *game, player_t *player)
{
    player->ejected = true;
    if (player->pos_x <= 0)
        player->pos_x = (game->map->width - 1);
    else
        player->pos_x--;
}
