/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** player_life
*/

#include "game.h"
#include "destruct.h"

void remove_player_from_list(team_t *team, player_t *player)
{
    player_t *current = team->players;
    player_t *prev = NULL;

    while (current != NULL) {
        if (current == player) {
            (prev == NULL) ?\
            (team->players = current->next) : (prev->next = current->next);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void remove_player(server_t *server, team_t *team)
{
    player_t *player = team->players;
    char *str_cmd = NULL;

    while (player) {
        if (player->dead) {
            player_t *next = player->next;
            printf("player: %d dead\n", player->id);
            remove_player_from_list(team, player);
            str_cmd = calloc(1, sizeof(char) * 10);
            sprintf(str_cmd, "pdi %d\n", player->id);
            pdi_cmd(NULL, server, str_cmd);
            free(str_cmd);
            destroy_player(player);
            player = next;
        } else
            player = player->next;
    }
}

void player_death(server_t *server, team_t *team)
{
    client_t *client = server->client;

    while (client) {
        if (client->player && client->player->dead) {
            send_msg(client->socket, "dead\n");
            disconnect_client(server, client);
        }
        client = client->next;
    }
    remove_player(server, team);
}

void player_life(team_t *team)
{
    player_t *player = team->players;

    while (player) {
        (player->life > 0) ? player->life-- : (player->dead = true);
        ((player->life % 126) == 1) ? player->rsc->food-- : 0;
        player = player->next;
    }
}
