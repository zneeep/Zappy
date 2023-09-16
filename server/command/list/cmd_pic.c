/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_pic
*/

#include "game.h"

void add_id_to_string(player_t *p, char *str)
{
    char *tmp = str;

    if (p->id < 10) {
        str = realloc(str, sizeof(char) * (strlen(str) + 3));
        sprintf(str, "%s %d", tmp, p->id);
    } else {
        str = realloc(str, sizeof(char) * (strlen(str) + 4));
        sprintf(str, "%s %d", tmp, p->id);
    }
}

void find_player_at_position_2(player_t *p, coord_t *c, char *str, int id)
{
    while (p != NULL) {
        if (p->pos_x == c->x && p->pos_y == c->y && p->id != id)
            add_id_to_string(p, str);
        p = p->next;
    }
}

char *find_player_at_position(team_t *teams, coord_t *coord, int id)
{
    player_t *p = NULL;
    char *str = NULL;
    coord_t *c = coord;

    while (teams != NULL) {
        p = teams->players;
        find_player_at_position_2(p, c, str, id);
        teams = teams->next;
    }
    return str;
}

void define_player_and_coord(server_t *server, player_t *p, coord_t *c, int id)
{
    p = find_player_with_id(server->game->teams, id);
    c = calloc(1, sizeof(coord_t));
    c->x = p->pos_x;
    c->y = p->pos_y;
}

void pic_cmd(client_t *client, server_t *server, char *str)
{
    char *msg = NULL;
    char *str_find = NULL;
    int id = -1;
    player_t *p = NULL;
    coord_t *c = NULL;

    strtok(str, " ");
    id = atoi(strtok(NULL, " "));
    if (id == -1)
        return;
    define_player_and_coord(server, p, c, id);
    str_find = find_player_at_position(server->game->teams, c, id);
    msg = calloc(1, sizeof(char) * 20 + strlen(str_find));
    sprintf(msg, "pic %d %d %d %d %s\n", p->pos_x, p->pos_y
    , p->level, id, str_find);
    send_msg_gui(server, msg);
    free(msg);
    free(c);
}
