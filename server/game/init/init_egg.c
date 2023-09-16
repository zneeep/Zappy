/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init_egg
*/

#include "game.h"

egg_t *create_egg(int id, int x, int y)
{
    egg_t *egg = calloc(1, sizeof(egg_t));

    if (egg == NULL)
        return (NULL);
    egg->id = id;
    egg->x = x;
    egg->y = y;
    return egg;
}

void insert_new_egg_at_end(team_t *team, int id, int x, int y)
{
    egg_t *new_egg = create_egg(id, x, y);

    if (team->eggs == NULL) {
        team->eggs = new_egg;
        return;
    } else {
        egg_t *tmp = team->eggs;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_egg;
    }
}
