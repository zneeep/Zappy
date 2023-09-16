/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** func_find_team
*/

#include "game.h"

char *find_team_name_with_player_id_next(int id, player_t *player,
team_t *teams)
{
    while (player != NULL) {
        if (player->id == id)
            return teams->name;
        player = player->next;
    }
    return NULL;
}

char *find_team_name_with_player_id(team_t *teams, int id)
{
    player_t *player = NULL;
    char *name = NULL;

    while (teams != NULL) {
        player = teams->players;
        if ((name = find_team_name_with_player_id_next(id, player, teams))\
        != NULL)
            return name;
        teams = teams->next;
    }
    return NULL;
}

team_t *find_team_with_name(team_t *teams, const char *name)
{
    if (name == NULL || !strcmp(name, "GRAPHIC"))
        return NULL;
    while (teams != NULL) {
        if (strcmp(teams->name, name) == 0)
            return teams;
        teams = teams->next;
    }
    return NULL;
}
