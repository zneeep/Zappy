/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** team
*/

#include "destruct.h"

void remove_client_from_team(team_t *team)
{
    team->nb_clients--;
}

void destroy_eggs(egg_t *egg)
{
    if (!egg->next)
        return;
    destroy_eggs(egg->next);
    free(egg);
}

void destroy_teams(team_t *team)
{
    if (!team)
        return;
    destroy_teams(team->next);
    destroy_players(team->players);
    printf("Destroy team: %s\n", team->name);
    free(team->name);
    team->players = NULL;
    team->nb_clients = 0;
    team->authorized_cli_nb = 0;
    team->nb_eggs = 0;
    if (team->eggs)
        destroy_eggs(team->eggs);
    free(team);
    team = NULL;
}
