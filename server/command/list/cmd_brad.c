/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** cmd_brad
*/

#include "game.h"

bool check_brad(server_t *server, client_t *c, char *command)
{
    if (c->player->incantating || c->player->fork || c->connected != 1) {
        send_msg(c->socket, "ko\n");
        return false;
    }
    return true;
}

client_t *find_client_from_p_id(server_t *server, int id)
{
    client_t *client = server->client;

    while (client != NULL) {
        if (client->player && client->player->id == id)
            return client;
        client = client->next;
    }
    return NULL;
}

void send_bradcast_cmd(server_t *server, player_t *player, char *str)
{
    client_t *client = find_client_from_p_id(server, player->id);

    if (!client)
        return;
    send_msg(client->socket, str);
}

void b_tile_player(server_t *s, player_t *src, player_t *dest, char *str)
{
    coord_t *result = NULL;
    char *buf = NULL;
    int tile = 0;

    result = get_vector(src, dest, s->game->map->height, s->game->map->width);
    tile = get_tile_from_co(result);
    tile = (tile + (2 * src->direction));
    if (tile > 8)
        tile -= 8;
    buf = calloc(1, sizeof(char) * (strlen(str) + 15));
    sprintf(buf, "message %d, %s\n", tile, str);
    send_bradcast_cmd(s, dest, buf);
    free(result);
    free(buf);
}

void brad_cmd(client_t *c, server_t *server, char *str)
{
    client_t *p = server->client;
    char *str_cmd = str;

    for (; str_cmd[0] && str_cmd[0] != ' '; str_cmd++);
    str_cmd++;
    while (p) {
        if (p->player && p->player != c->player)
            b_tile_player(server, c->player, p->player, str_cmd);
        p = p->next;
    }
    pbc_cmd(c, server, str_cmd);
    send_msg(c->socket, "ok\n");
}
