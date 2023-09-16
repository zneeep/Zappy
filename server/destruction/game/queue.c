/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** queue
*/

#include "game.h"

void remove_client_queue_cmd(server_t *server, client_t *client)
{
    queue_t *current = server->queue;
    queue_t *prev = NULL;
    queue_t *remove = NULL;

    if (!current)
        return;
    while (current != NULL) {
        if (current->client->number == client->number) {
            remove = current;
            (prev == NULL) ?\
            (server->queue = current->next) : (prev->next = current->next);
            free_command(remove);
        }
        prev = current;
        current = current->next;
    }
}
