/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** parse
*/

#include "commandes.h"
#include "tools.h"
#include "init.h"

void wrong_or_unknown_command(client_t *client)
{
    printf("Wrong or not allowed command\n");
    send(client->socket, "ko\n", 4, 0);
}

int check_command(server_t *server, client_t *client, char **cmd, int i)
{
    if (strcmp(cmd[0], commands[i].name) != 0)
        return 0;
    if (client->connected == 0)
        if (check_graphic(server, client, cmd[0]))
            return 2;
    if (client->player || client->connected == 2)
        return 1;
    wrong_or_unknown_command(client);
    return 2;
}

void add_cmd_to_queue(server_t *server, client_t *client, char *cmd, int i)
{
    queue_t *queue = server->queue;
    queue_t *new_queue = calloc(1, sizeof(queue_t));

    (!client->nb_request) ? (new_queue->first = 1) : (new_queue->first = 0);
    client->nb_request++;
    new_queue->freq = commands[i].freq;
    new_queue->base_freq = commands[i].freq;
    new_queue->client = client;
    new_queue->command = strdup(cmd);
    new_queue->next = NULL;
    if (!server->queue) {
        server->queue = new_queue;
        return;
    }
    while (queue->next != NULL)
        queue = queue->next;
    queue->next = new_queue;
}

void parse_command_2(server_t *server, client_t *client, char **tab)
{
    if (!client->connected) {
        check_for_name(server, client, tab[0]);
    } else
        wrong_or_unknown_command(client);
}

void parse_command(server_t *server, client_t *client, char *command)
{
    char **tab = NULL;
    int found = 0;

    if (client->connected == 1 && client->nb_request >= 10)
        return;
    tab = calloc(1, sizeof(char *) * get_size_tab(command, ' '));
    tab = get_tab(tab, command, ' ');
    for (int i = 0; commands[i].name; i++) {
        if ((found = check_command(server, client, tab, i)) == 1) {
            free_double_ptr(tab);
            return add_cmd_to_queue(server, client, command, i);
        }
        if (found == 2)
            return free_double_ptr(tab);
    }
    parse_command_2(server, client, tab);
    free_double_ptr(tab);
}
