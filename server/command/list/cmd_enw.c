/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_enw
*/

#include "game.h"

void enw_cmd(client_t *client, server_t *server, char *str)
{
    char **tab = calloc(1, sizeof(char *) * 3);
    char *msg = NULL;
    player_t *player = NULL;
    int id = 0;
    int egg_i = 0;

    tab = get_tab(tab, str, ' ');
    id = atoi(tab[0]);
    egg_i = atoi(tab[1]);
    if (!(player = find_player_with_id(server->game->teams, id)))
        return free_double_ptr(tab);
    msg = calloc(1, sizeof(char) * 30);
    sprintf(msg, "enw %d %d %d %d\n", egg_i, id, player->pos_x, player->pos_y);
    send_msg_gui(server, msg);
    free(msg);
    free_double_ptr(tab);
}
