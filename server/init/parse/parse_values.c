/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** parse_values
*/

#include "init.h"

bool parse_check_freq(server_t *server, char *str_freq)
{
    float freq = 0;

    if (!str_freq)
        return false;
    if ((freq = atof(str_freq)) <= 0)
        return false;
    server->init->frequency = freq;
    return true;
}

bool parse_check_clients_nb(server_t *server, char *str_clients_nb)
{
    int clients_nb = 0;

    if ((clients_nb = atoi(str_clients_nb)) <= 0)
        return false;
    server->init->authorized_cli_nb = clients_nb;
    return true;
}

bool parse_check_port(server_t *server, char *str_port)
{
    int port = 0;

    if ((port = atoi(str_port)) <= 0)
        return false;
    server->init->port = port;
    return true;
}
