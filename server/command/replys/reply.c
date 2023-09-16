/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** reply
*/

#include "server.h"
#include "game.h"
#include "commandes.h"

client_t *find_client_from_socket(server_t *server, int socket)
{
    client_t *client = server->client;

    while (client != NULL) {
        if (client->socket == socket)
            return client;
        client = client->next;
    }
    return NULL;
}

int get_func_by_name(char *name)
{
    int i = 0;

    for (; cmd_check[i].name; i++) {
        if (!strcmp(cmd_check[i].name, name))
            return i;
    }
    return -1;
}

void call_command_queue(server_t *server, queue_t *current)
{
    char *name = NULL;

    if (!strcmp(current->command, "Connect_nbr"))
        return co_nbr_cmd(server, current->client->socket);
    name = get_first_arg(current->command, ' ');
    printf("\033[1;31mCall c %d: %s\n\033[0m", current->client->number, name);
    for (int i = 0; cmds[i].name; i++) {
        if (cmds[i].func && !strcmp(name, cmds[i].name)) {
            cmds[i].func(current->client, server, current->command);
            break;
        }
    }
    if (name)
        free(name);
}

bool check_cmd(server_t *server, queue_t *c)
{
    int i = 0;

    if (c->first && (((c->freq + 1) == c->base_freq) || c->base_freq == 0)) {
        char *name = NULL;
        name = get_first_arg(c->command, ' ');
        if ((i = get_func_by_name(name)) == -1)
            return true;
        free(name);
        return cmd_check[i].func(server, c->client, c->command);
    }
    return true;
}

void reply(server_t *server)
{
    queue_t *c = server->queue;
    queue_t *prv = NULL;

    while (c && c->command) {
        (c->first && c->freq > 0) ? c->freq-- : 0;
        if (check_cmd(server, c) == false) {
            process_invalid_cmd(server, &c, &prv);
            continue;
        }
        if (c && !c->freq && c->first) {
            process_completed_cmd(server, &c, &prv);
            continue;
        }
        prv = c;
        c = c->next;
    }
}
