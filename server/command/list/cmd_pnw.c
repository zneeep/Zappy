/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_pnw
*/

#include "game.h"

void pnw_cmd(client_t *client, server_t *server, char *str)
{
    player_t *player = NULL;
    char *msg = NULL;
    int id = 0;

    id = atoi(str);
    msg = calloc(1, sizeof(char) * 50);
    player = find_player_with_id(server->game->teams, id);
    sprintf(msg, "pnw %d %d %d %d %d %s\n", id, player->pos_x, player->pos_y,
        player->direction, player->level,
        find_team_name_with_player_id(server->game->teams, id));
    send_msg_gui(server, msg);
    free(msg);
}
