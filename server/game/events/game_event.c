/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** game_event
*/

#include "game.h"

void team_win(server_t *server, team_t *team)
{
    seg_cmd(server->client, server, team->name);
    printf("End of game, team %s win\n", team->name);
    server->stop = true;
}

void reach_end_of_game(server_t *server, int nb_cli)
{
    if (nb_cli <= 0) {
        seg_cmd(server->client, server, "Nobody");
        printf("End of game nobody win\n");
        server->stop = true;
    }
}

void end_game(server_t *server)
{
    team_t *current = server->game->teams;
    player_t *player = NULL;
    int nb_cli = 0;

    while (current) {
        int level = 0;
        player = current->players;
        while (player) {
            nb_cli++;
            (player->level == 8) ? level++ : 0;
            player = player->next;
        }
        if (level > 5)
            return team_win(server, current);
        current = current->next;
    }
    reach_end_of_game(server, nb_cli);
}

void game_process(server_t *server)
{
    team_t *team = server->game->teams;

    server->game->spawn++;
    while (team != NULL) {
        player_life(team);
        player_death(server, team);
        team = team->next;
    }
    eject_effect(server->client);
    if (server->game->spawn >= 19) {
        printf("\033[1;34m--Map regenerated--\n\033[0m");
        map_resources_management(server->game);
        server->game->spawn = 0;
    }
    end_game(server);
}

void game_event(server_t *server)
{
    client_t *client = server->client;

    if (server->start)
        game_process(server);
    else {
        while (client) {
            (client->connected == 1) ? (server->start = true) : 0;
            client = client->next;
        }
    }
}
