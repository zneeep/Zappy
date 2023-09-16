/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_forward
*/

#include "game.h"

bool check_forward(server_t *server, client_t *c, char *command)
{
    if (c->player->incantating || c->player->fork || c->connected != 1) {
        send_msg(c->socket, "ko\n");
        return false;
    }
    return true;
}

void check_position(client_t *client, game_t *game)
{
    if (client->player->pos_x >= game->map->width)
        client->player->pos_x = 0;
    if (client->player->pos_x < 0)
        client->player->pos_x = (game->map->width - 1);
    if (client->player->pos_y >= game->map->height)
        client->player->pos_y = 0;
    if (client->player->pos_y < 0)
        client->player->pos_y = (game->map->height - 1);
}

void forward_cmd(client_t *client, server_t *server, char *str)
{
    char *str_cmd = NULL;

    if (!client || !client->player)
        return;
    if (client->player->direction == 0)
        client->player->pos_y--;
    if (client->player->direction == 1)
        client->player->pos_x++;
    if (client->player->direction == 2)
        client->player->pos_y++;
    if (client->player->direction == 3)
        client->player->pos_x--;
    check_position(client, server->game);
    send_msg(client->socket, "ok\n");
    str_cmd = calloc(1, sizeof(char) * 10);
    sprintf(str_cmd, "%d", client->number);
    ppo_cmd(client, server, str_cmd);
    free(str_cmd);
}
