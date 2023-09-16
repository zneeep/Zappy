/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server
*/

#include "init.h"
#include "destruct.h"
#include "game.h"

int main(int argc, char **argv)
{
    server_t *server = calloc(1, sizeof(server_t));

    check_input(server, argc, argv);
    if (!init(server))
        return 84;
    if (!init_game(server))
        return 84;
    while (!server->stop) {
        if (setup_server_readfds(server) < 0)
            return 84;
        new_connection(server);
        receive_msg(server);
        reply(server);
        game_event(server);
    }
    destroy(server);
    return 0;
}
