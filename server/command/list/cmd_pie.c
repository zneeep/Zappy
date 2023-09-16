/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_pie
*/

#include "game.h"

void pie_cmd(client_t *client, server_t *server, char *str)
{
    char *msg = NULL;
    player_t *p = NULL;
    int id = 0;
    int incant_state = 0;

    strtok(str, " ");
    id = atoi(strtok(NULL, " "));
    incant_state = atoi(strtok(NULL, " "));
    p = find_player_with_id(server->game->teams, id);
    msg = calloc(1, sizeof(char) * 30);
    sprintf(msg, "pie %d %d %d %d\n", id, p->pos_x, p->pos_y, incant_state);
    send_msg_gui(server, msg);
    free(msg);
}
