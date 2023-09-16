/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_sst
*/

#include "game.h"

void sst_cmd(client_t *client, server_t *server, char *str)
{
    char *msg = NULL;
    float time_unit = 0;
    int words = 0;
    int len = 0;

    for (; str[len]; len++)
        if (str[len] == ' ')
            words++;
    if (words >= 1 && len >= 4) {
        send_msg_gui(server, str);
        strtok(str, " ");
        if ((time_unit = atof(strtok(NULL, " "))) >= 0.0)
            server->init->frequency = time_unit;
        free(msg);
    }
}

bool check_sst(server_t *server, client_t *client, char *command)
{
    char **tab = NULL;
    int nb = 0;

    if (client->connected != 2)
        return false;
    tab = calloc(1, sizeof(char *) * get_size_tab(command, ' '));
    tab = get_tab(tab, command, ' ');
    if (!tab[1] || (nb = atoi(tab[1])) < 0) {
        free_double_ptr(tab);
        return false;
    }
    free_double_ptr(tab);
    return true;
}
