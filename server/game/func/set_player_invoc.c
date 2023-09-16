/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** set_player_invoc
*/

#include "game.h"

void send_player_invoc_start(server_t *server, player_t *player)
{
    client_t *client = find_client_from_p_id(server, player->id);

    if (!client || player->incantating || player->fork)
        return;
    player->incantating = true;
    send_msg(client->socket, "Elevation underway\n");
}

void set_player_invoc(server_t *server, int x, int y)
{
    team_t *team = server->game->teams;
    player_t *p = NULL;

    while (team) {
        p = team->players;
        while (p) {
            p = find_player_with_co(p, x, y);
            (p != NULL) ? send_player_invoc_start(server, p) : 0;
            (p != NULL) ? (p = p->next) : 0;
        }
        team = team->next;
    }
}

void send_player_invoc_end(server_t *server, player_t *player, char *str)
{
    client_t *client = find_client_from_p_id(server, player->id);

    if (!client || !player->incantating)
        return;
    send_msg(client->socket, str);
}

void remove_player_invoc(server_t *server, int x, int y, char *str)
{
    team_t *team = server->game->teams;
    player_t *p = NULL;

    while (team) {
        p = team->players;
        while (p) {
            p = find_player_with_co(p, x, y);
            (p != NULL) ? send_player_invoc_end(server, p, str) : 0;
            (p != NULL) ? p->incantating = false : 0;
            (p != NULL) ? p = p->next : 0;
        }
        team = team->next;
    }
}
