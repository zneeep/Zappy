/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** egg
*/

#include "game.h"
#include "tools.h"

void remove_egg_from_list(team_t *team, egg_t *egg)
{
    egg_t *current = team->eggs;
    egg_t *prev = NULL;

    while (current != NULL) {
        if (current == egg) {
            (prev == NULL) ?\
            (team->eggs = current->next) : (prev->next = current->next);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void free_egg(egg_t *egg)
{
    egg->next = NULL;
    free(egg);
}

egg_t *find_egg_with_co(egg_t *player, int x, int y)
{
    egg_t *current = player;

    while (current) {
        if (current->x == x && current->y == y)
            return current;
        current = current->next;
    }
    return NULL;
}

char *int_to_char(int nbr)
{
    char *str = NULL;

    str = calloc(1, sizeof(char) * 10);
    sprintf(str, "%d", nbr);
    return str;
    free(str);
}

void action_on_egg(server_t *server, client_t *client, game_t *game)
{
    team_t *team = game->teams;
    egg_t *current = NULL;
    egg_t *prv = NULL;
    int x = client->player->pos_x;
    int y = client->player->pos_y;

    while (team) {
        current = team->eggs;
        while (current) {
            current = find_egg_with_co(current, x, y);
            (current) ? remove_egg_from_list(team, current) : 0;
            (current) ? prv = current : 0;
            (current) ? current = current->next : 0;
            (current) ? free_egg(prv) : 0;
            (current) ? team->authorized_cli_nb-- : 0;
            (current) ? edi_cmd(client, server, int_to_char(current->id)) : 0;
        }
        team = team->next;
    }
}
