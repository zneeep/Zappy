/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** fonc
*/

#include "game.h"

resources_t modif_resources_cell_3(resources_t rsc, const char *type, int qty)
{
    if (strcmp(type, "mendiane") == 0)
        rsc.mendiane += qty;
    else if (strcmp(type, "phiras") == 0)
        rsc.phiras += qty;
    else
        rsc.thystame += qty;
    return rsc;
}

resources_t modif_resources_cell_2(resources_t rsc, const char *type, int qty)
{
    if (strcmp(type, "deraumere") == 0)
        rsc.deraumere += qty;
    else if (strcmp(type, "sibur") == 0)
        rsc.sibur += qty;
    else
        return modif_resources_cell_3(rsc, type, qty);
    return rsc;
}

resources_t modif_resources_cell(resources_t rsc, const char *type, int qty)
{
    if (strcmp(type, "food") == 0)
        rsc.food += qty;
    else if (strcmp(type, "linemate") == 0)
        rsc.linemate += qty;
    else
        return modif_resources_cell_2(rsc, type, qty);
    return rsc;
}
