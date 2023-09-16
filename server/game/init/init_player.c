/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init_player
*/

#include "game.h"

resources_t *declare_resources_player(void)
{
    resources_t *rsc = NULL;

    rsc = calloc(1, sizeof(resources_t));
    rsc->food = 10;
    rsc->linemate = 0;
    rsc->deraumere = 0;
    rsc->sibur = 0;
    rsc->mendiane = 0;
    rsc->phiras = 0;
    rsc->thystame = 0;
    return rsc;
}

player_t *create_player_cell(coord_t *coord, int id)
{
    player_t *player = calloc(1, sizeof(player_t));

    if (player == NULL)
        return NULL;
    player->id = id;
    player->direction = rand() % 4;
    player->dead = false;
    player->ejected = false;
    player->fork = false;
    player->incantating = 0;
    player->level = 1;
    player->life = 1260;
    player->next = NULL;
    player->pos_x = coord->x;
    player->pos_y = coord->y;
    player->rsc = declare_resources_player();
    return player;
}

void insert_new_player_at_end(player_t **head, coord_t *coord, int id)
{
    player_t *new_player = create_player_cell(coord, id);

    if (*head == NULL) {
        *head = new_player;
        return;
    } else {
        player_t *tmp = *head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_player;
    }
}

void create_all_players(team_t *team, init_t *init, int nb)
{
    coord_t *coord = calloc(1, sizeof(coord_t));
    nb = nb * init->authorized_cli_nb;

    for (int i = 0; i < init->authorized_cli_nb; i++) {
        coord->x = rand() % init->width;
        coord->y = rand() % init->height;
        insert_new_player_at_end(&team->players, coord, (nb + i));
        init->last_id = (nb + i);
    }
    free(coord);
}
