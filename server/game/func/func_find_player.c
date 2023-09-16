/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** fonc_find
*/

#include "game.h"

player_t *find_player_with_id_2(player_t *player, int id)
{
    while (player != NULL) {
        if (player->id == id)
            return player;
        player = player->next;
    }
    return NULL;
}

player_t *find_player_with_id(team_t *teams, int id)
{
    player_t *player = NULL;

    while (teams != NULL) {
        player = teams->players;
        if ((player = find_player_with_id_2(player, id)) != NULL)
            return player;
        teams = teams->next;
    }
    return NULL;
}

void update_player_list(client_t *client, int (*ids)[2], int index)
{
    for (int i = 0; i < index; i++)
        if (client->player && client->player->id == ids[i][0])
            ids[i][1] = 1;
}

void get_ids_list(team_t *team, int (*ids)[2], int *index)
{
    player_t *current = team->players;

    while (current) {
        ids[(*index)++][0] = current->id;
        current = current->next;
    }
}

int found_player_id_available(server_t *server, team_t *team)
{
    client_t *client = server->client;
    int (*ids)[2] = calloc(server->init->last_id, sizeof(int[2]));
    int index = 0;
    int id = -1;

    get_ids_list(team, ids, &index);
    while (client) {
        if (client->team && !strcmp(client->team, team->name))
            update_player_list(client, ids, index);
        client = client->next;
    }
    for (int i = 0; i < index; i++)
        if (!ids[i][1]) {
            id = ids[i][0];
            break;
        }
    free(ids);
    return id;
}
