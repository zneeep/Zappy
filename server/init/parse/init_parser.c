/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_parser
*/

#include "init.h"
#include "server.h"

void init_game_parser(server_t *server)
{
    server->init->port = 4242;
    server->init->width = 10;
    server->init->height = 10;
    server->init->teams_nb = 0;
    server->init->frequency = 100.0;
    server->init->authorized_cli_nb = 2;
    server->init->team_names[0] = NULL;
}
