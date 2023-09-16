/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_graphic
*/

#include "game.h"
#include "init.h"

void print_client(server_t *server, int socket)
{
    client_t *current = server->client;

    while (current != NULL) {
        current = current->next;
    }
}

void send_existing_players(server_t *server, team_t *team)
{
    client_t *c = server->client;
    char *str_cmd = calloc(1, sizeof(char) * 3);

    while (c) {
        if (c->player) {
            sprintf(str_cmd, "%d", c->player->id);
            pnw_cmd(NULL, server, str_cmd);
        }
        c = c->next;
    }
    free(str_cmd);
}

void graphic_cmd(server_t *server, client_t *client, int socket)
{
    client_t *current = server->client;
    client_t *new = NULL;

    new = init_client_values(new, 0);
    new->number = ++server->init->last_id;
    new->player = client->player;
    client->player = NULL;
    while (current->next)
        current = current->next;
    current->next = new;
    send_existing_players(server, server->game->teams);
}

bool check_graphic(server_t *server, client_t *client, char *command)
{
    if (client->connected)
        return false;
    client->connected = 2;
    client->team = strdup(command);
    msz_cmd(client, server, NULL);
    sgt_cmd(client, server, NULL);
    mct_cmd(client, server, NULL);
    tna_cmd(client, server, NULL);
    graphic_cmd(server, client, client->socket);
    return true;
}
