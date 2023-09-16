/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** init_server
*/

#include "init.h"

bool init(server_t *server)
{
    int nb_client = server->init->teams_nb * server->init->authorized_cli_nb;

    server->client = NULL;
    if (!init_server(server, server->init->port))
        return false;
    server->client = init_clients(nb_client);
    return true;
}
