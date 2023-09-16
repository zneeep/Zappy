/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** queue
*/

#include "game.h"

void free_command(queue_t *queue)
{
    queue->freq = -1;
    queue->client = NULL;
    queue->first = false;
    if (queue->command != NULL)
        free(queue->command);
    if (queue != NULL)
        free(queue);
}

void get_next_command(server_t *server, queue_t *queue)
{
    client_t *client = queue->client;
    queue_t *temp = server->queue;
    queue_t *prev = NULL;

    if (!queue)
        return;
    (client != NULL) ? client->nb_request-- : 0;
    while (temp != NULL) {
        if (temp == queue) {
            (prev == NULL) ?\
            (server->queue = temp->next) : (prev->next = temp->next);
            return free_command(temp);
        }
        prev = temp;
        temp = temp->next;
    }
    return free_command(queue);
}

void process_invalid_cmd(server_t *server, queue_t **c, queue_t **prv)
{
    queue_t *remove = (*c);

    ((*prv) == NULL) ?\
    (server->queue = (*c)->next) : ((*prv)->next = (*c)->next);
    (*c) = (*c)->next;
    get_next_command(server, remove);
}

void process_completed_cmd(server_t *server, queue_t **c, queue_t **prv)
{
    queue_t *remove = (*c);

    if ((*c)->client->player) {
        if (!(*c)->client->player->incantating
        || !strcmp((*c)->command, "Incantation"))
            call_command_queue(server, (*c));
    } else
        call_command_queue(server, (*c));
    ((*prv) == NULL) ?\
    (server->queue = (*c)->next) : ((*prv)->next = (*c)->next);
    (*c) = (*c)->next;
    get_next_command(server, remove);
}
