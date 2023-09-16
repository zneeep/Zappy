/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** disconnexion
*/

#include "destruct.h"
#include "game.h"

void disconnect_client(server_t *server, client_t *client)
{
    team_t *team = find_team_with_name(server->game->teams, client->team);

    if (team != NULL)
        remove_client_from_team(team);
    remove_client_queue_cmd(server, client);
    FD_CLR(client->socket, &server->readfds);
    printf("User disconnected\n");
    renit_client_values(client);
}
