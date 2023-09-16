/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** client
*/

#include "destruct.h"
#include "game.h"

void renit_client_values(client_t *client)
{
    client->connected = false;
    client->nb_request = 0;
    client->number = 0;
    client->player = NULL;
    if (client->team)
        free(client->team);
    client->team = NULL;
    client->socket = 0;
}

void remove_client_from_list(server_t *server, client_t *client)
{
    client_t *current = server->client;
    client_t *prev = NULL;

    while (current != NULL) {
        if (current == client) {
            (prev == NULL) ?\
            (server->client = current->next) : (prev->next = current->next);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void remove_client(server_t *server, client_t *client)
{
    FD_CLR(client->socket, &server->readfds);
    if (client->socket > 0)
        close(client->socket);
    printf("User disconnected\n");
    remove_client_from_list(server, client);
    renit_client_values(client);
    free(client);
}

void client_destroy(server_t *server)
{
    client_t *client = server->client;
    client_t *remove = NULL;

    while (client) {
        FD_CLR(client->socket, &server->readfds);
        if (client->socket > 0)
            close(client->socket);
        remove_client_from_list(server, client);
        renit_client_values(client);
        remove = client;
        client = client->next;
        free(remove);
    }
}
