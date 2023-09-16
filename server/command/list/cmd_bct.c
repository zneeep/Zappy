/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_bct
*/

#include "game.h"

bool check_bct(server_t *server, client_t *client, char *command)
{
    char **tab = NULL;
    int nb = 0;
    bool value = true;

    if (client->connected != 2)
        return false;
    tab = calloc(1, sizeof(char *) * get_size_tab(command, ' '));
    tab = get_tab(tab, command, ' ');
    nb = atoi(tab[1]);
    if (nb < 0 || nb > server->init->width)
        value = false;
    nb = atoi(tab[2]);
    if (nb < 0 || nb > server->init->height)
        value = false;
    free_double_ptr(tab);
    return value;
}

void bct_bis_cmd(int socket, game_t *game, int x, int y)
{
    char *buf = calloc(1, sizeof(char) * 40);

    sprintf(buf, "bct %d %d %d %d %d %d %d %d %d\n", x, y,\
    game->map->rsc[x][y].food, game->map->rsc[x][y].linemate,\
    game->map->rsc[x][y].deraumere, game->map->rsc[x][y].sibur,\
    game->map->rsc[x][y].mendiane, game->map->rsc[x][y].phiras,\
    game->map->rsc[x][y].thystame);
    send_msg(socket, buf);
    free(buf);
}

void bct_cmd(client_t *client, server_t *server, char *str)
{
    char **tab = calloc(1, sizeof(char *) * get_size_tab(str, ' '));
    char *buf = calloc(1, sizeof(char) * 40);
    resources_t **rsc = server->game->map->rsc;
    int x = 0;
    int y = 0;

    tab = get_tab(tab, str, ' ');
    x = atoi(tab[1]);
    y = atoi(tab[2]);
    sprintf(buf, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
    rsc[x][y].food, rsc[x][y].linemate, rsc[x][y].deraumere, rsc[x][y].sibur,
    rsc[x][y].mendiane, rsc[x][y].phiras, rsc[x][y].thystame);
    send_msg(client->socket, buf);
    free(buf);
}
