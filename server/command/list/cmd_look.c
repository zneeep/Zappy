/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_look
*/

#include "game.h"

bool check_look(server_t *server, client_t *c, char *command)
{
    if (c->player->incantating || c->player->fork || c->connected != 1) {
        send_msg(c->socket, "ko\n");
        return false;
    }
    return true;
}

void get_tile_content(char **buf, resources_t tile)
{
    get_tile_deraumere(buf, tile.deraumere);
    get_tile_food(buf, tile.food);
    get_tile_linemate(buf, tile.linemate);
    get_tile_mendiane(buf, tile.mendiane);
    get_tile_phiras(buf, tile.phiras);
    get_tile_sibur(buf, tile.sibur);
    get_tile_thystame(buf, tile.thystame);
}

char *add_comma(char *buf)
{
    if (buf == NULL)
        return NULL;
    size_t len = strlen(buf);
    buf = realloc(buf, sizeof(char) * (len + 2));
    strcat(buf, ",");
    return buf;
}

char *look(game_t *g, player_t *p, char *buf, int i)
{
    coord_t *co = NULL;

    for (int j = 0; j < (2 * i + 1); j++) {
        if (p->direction == 0)
            co = get_look_coord_0(g, p, i, j);
        if (p->direction == 1)
            co = get_look_coord_1(g, p, i, j);
        if (p->direction == 2)
            co = get_look_coord_2(g, p, i, j);
        if (p->direction == 3)
            co = get_look_coord_3(g, p, i, j);
        get_tile_player(g, &buf, co->y, co->x);
        get_tile_content(&buf, g->map->rsc[co->y][co->x]);
        buf = add_comma(buf);
        free(co);
    }
    return buf;
}

void look_cmd(client_t *client, server_t *server, char *str)
{
    char *response = NULL;
    char *buf = NULL;
    size_t len = 0;

    for (int i = 0; i <= client->player->level; i++)
        buf = look(server->game, client->player, buf, i);
    len = strlen(buf);
    buf[len - 1] = ']';
    response = calloc(1, sizeof(char) * (len + 3));
    sprintf(response, "[%s\n", buf);
    send_msg(client->socket, response);
    if (response)
        free(response);
    if (buf)
        free(buf);
}
