/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** destruction
*/

#include "server.h"
#include "destruct.h"

void destroy(server_t *server)
{
    init_destroy(server);
    client_destroy(server);
    game_destroy(server);
    free(server);
}
