/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_plv
*/

#include "game.h"

void plv_cmd_bis(server_t *server, char *str)
{
    player_t *player = NULL;
    char *msg = NULL;
    int id = 0;

    strtok(str, " ");
    id = atoi(strtok(NULL, " "));
    msg = calloc(1, sizeof(char) * 10);
    player = find_player_with_id(server->game->teams, id);
    sprintf(msg, "plv %d %d\n", id, player->level);
    send_msg_gui(server, msg);
    free(msg);
}

void plv_cmd(client_t *client, server_t *server, char *str)
{
    int len = 0;
    int words = 0;

    for (; str[len]; len++)
        if (str[len] == ' ')
            words++;
    if (words >= 1 && len >= 4)
        plv_cmd_bis(server, str);
}

bool check_plv(server_t *server, client_t *client, char *command)
{
    char **tab = NULL;
    int nb = 0;

    if (client->connected != 2)
        return false;
    tab = calloc(1, sizeof(char *) * get_size_tab(command, ' '));
    tab = get_tab(tab, command, ' ');
    nb = atoi(tab[1]);
    if (nb < 0 || nb >= server->init->last_id) {
        free_double_ptr(tab);
        return false;
    }
    free_double_ptr(tab);
    return true;
}
