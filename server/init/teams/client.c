/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** client
*/

#include "init.h"
#include "game.h"

client_t *init_client_values(client_t *client, int socket)
{
    client = calloc(1, sizeof(client_t));
    client->next = NULL;
    client->team = NULL;
    client->player = NULL;
    client->connected = 0;
    client->nb_request = 0;
    client->socket = socket;
    return client;
}

void init_client(server_t *server, int socket)
{
    client_t *client = server->client;
    client_t *new_client = NULL;
    int nb = 0;

    new_client = init_client_values(new_client, socket);
    if (!client) {
        server->client = new_client;
    } else {
        while (client->next != NULL) {
            nb++;
            client = client->next;
        }
        new_client->number = nb + 1;
        client->next = new_client;
    }
}

client_t *init_clients(int nb_client)
{
    client_t *head = NULL;
    client_t *prev = NULL;

    for (int i = 0; i < nb_client; i++) {
        client_t *new_client = NULL;
        new_client = init_client_values(new_client, 0);
        new_client->number = i;
        if (head == NULL)
            head = new_client;
        if (prev != NULL)
            prev->next = new_client;
        prev = new_client;
    }
    return head;
}
