/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init
*/

#include "server.h"

void init_destroy(server_t *server)
{
    for (int i = 0; server->init->team_names[i]; i++)
        free(server->init->team_names[i]);
    free(server->init);
}
