/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_pin
*/

#include "game.h"

bool check_pin(server_t *server, client_t *client, char *command)
{
    char **tab = NULL;
    int nb = 0;

    if (client->connected != 2)
        return false;
    tab = calloc(1, sizeof(char *) * get_size_tab(command, ' '));
    tab = get_tab(tab, command, ' ');
    nb = atoi(tab[1]);
    if (nb < 0 || nb > server->nb_clients) {
        free_double_ptr(tab);
        return false;
    }
    free_double_ptr(tab);
    return true;
}

void pin_cmd(client_t *client, server_t *server, char *str)
{
    player_t *player = NULL;
    char *msg = NULL;
    int id = 0;

    id = atoi(str);
    if (!(player = find_player_with_id(server->game->teams, id)))
        return;
    msg = calloc(1, sizeof(char) * 50);
    sprintf(msg, "pin %d %d %d %d %d %d %d %d %d\n"
    , id, player->level, player->rsc->food, player->rsc->linemate
    , player->rsc->deraumere, player->rsc->sibur, player->rsc->mendiane
    , player->rsc->phiras, player->rsc->thystame);
    send_msg_gui(server, msg);
    free(msg);
}
