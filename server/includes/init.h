/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init
*/

#ifndef INIT_H_
    #define INIT_H_

    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>

    #include "server.h"

    void parse(server_t *server, int argc, char **argv);
    bool parse_check_name(server_t *server, char **av);
    bool parse_check_freq(server_t *server, char *freq);
    bool parse_check_clients_nb(server_t *server, char *clients_nb);
    bool parse_check_port(server_t *server, char *port);
    bool parse_check_height(server_t *server, char *height);
    bool parse_check_width(server_t *server, char *width);
    void init_game_parser(server_t *server);

    void get_help(char *arg);
    void check_input(server_t *server, int argc, char **argv);
    void add_name(server_t *server, char *name);

    bool init(server_t *server);
    void init_client(server_t *server, int socket);
    bool init_server(server_t *server, int port);
    client_t *init_clients(int nb_clients);

    client_t *init_client_values(client_t *client, int socket);
    void add_client_to_team(team_t *teams, client_t *client,
    char *name, int id);
    int setup_server_readfds(server_t *server);
    void new_connection(server_t *server);

#endif /* !INIT_H_ */
