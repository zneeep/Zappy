/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** parse
*/

#include "init.h"

void quit_parse(server_t *server)
{
    for (int i = 0; server->init->team_names[i]; i++)
        free(server->init->team_names[i]);
    free(server->init);
    free(server);
}

bool get_flag(server_t *server, char **av)
{
    char *flag = av[server->init->ac_pos];

    if (flag[0] != '-' || strlen(av[server->init->ac_pos]) != 2)
        return false;
    switch (flag[1]) {
        case 'p':
            return parse_check_port(server, av[++server->init->ac_pos]);
        case 'x':
            return parse_check_width(server, av[++server->init->ac_pos]);
        case 'y':
            return parse_check_height(server, av[++server->init->ac_pos]);
        case 'n':
            return parse_check_name(server, av);
        case 'c':
            return parse_check_clients_nb(server, av[++server->init->ac_pos]);
        case 'f':
            return parse_check_freq(server, av[++server->init->ac_pos]);
        default:
            return false;
    }
}

void init_base_teams(server_t *server)
{
    add_name(server, "Team1");
    add_name(server, "Team2");
    add_name(server, "Team3");
    add_name(server, "Team4");
}

bool check_flag(server_t *server)
{
    if (server->init->height == 0 || server->init->width == 0
    || server->init->frequency == 0 || server->init->authorized_cli_nb == 0
    || server->init->port == 0)
        return false;
    if (server->init->teams_nb == 0)
        init_base_teams(server);
    return true;
}

void parse(server_t *server, int argc, char **argv)
{
    server->init = calloc(1, sizeof(init_t));

    server->init->ac_pos = 1;
    init_game_parser(server);
    for (; server->init->ac_pos < argc; server->init->ac_pos++)
        if (!get_flag(server, argv)) {
            quit_parse(server);
            exit(84);
        }
    if (!check_flag(server)) {
        quit_parse(server);
        exit(84);
    }
}
