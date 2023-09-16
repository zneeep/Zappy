/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** parse_names
*/

#include "init.h"

/*
    Check si :
        - Name already exist
        - Size of name
        - Valid name
    Si nom invalide skip
*/

void add_name(server_t *server, char *name)
{
    int team_nb = server->init->teams_nb;

    for (int i = 0; i < team_nb; i++)
        if (!strcmp(server->init->team_names[i], name))
            return;
    if (strlen(name) >= NAME_SIZE)
        return;
    server->init->team_names[team_nb] = NULL;
    server->init->team_names[team_nb] = strdup(name);
    server->init->team_names[team_nb + 1] = NULL;
    server->init->teams_nb++;
}

bool parse_check_name(server_t *server, char **av)
{
    int i = server->init->ac_pos + 1;

    for (; av[i] != NULL; i++) {
        if (av[i][0] == '-')
            break;
        add_name(server, av[i]);
    }
    server->init->ac_pos = i - 1;
    return true;
}
