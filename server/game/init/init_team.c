/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init_team
*/

#include "game.h"

team_t *create_team_cell(init_t *init, int nb)
{
    team_t *team = calloc(1, sizeof(team_t));

    if (team == NULL)
        return NULL;
    team->name = strdup(init->team_names[nb]);
    team->players = NULL;
    team->nb_clients = 0;
    team->authorized_cli_nb = init->authorized_cli_nb;
    team->eggs = NULL;
    team->nb_eggs = 0;
    create_all_players(team, init, nb);
    team->next = NULL;
    return team;
}

void insert_new_team_at_end(team_t **head, init_t *init, int nb)
{
    team_t *new_team = create_team_cell(init, nb);

    if (*head == NULL) {
        *head = new_team;
        return;
    } else {
        team_t *tmp = *head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_team;
    }
}

void create_all_teams(game_t *game, init_t *init)
{
    for (int i = 0; i < game->nb_teams; i++)
        insert_new_team_at_end(&game->teams, init, i);
}

bool init_teams(game_t *game, init_t *init)
{
    game->teams = NULL;
    game->nb_teams = init->teams_nb;
    create_all_teams(game, init);
    return true;
}
