/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <uuid/uuid.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <string.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdint.h>

    #include "tools.h"

    #define NAME_SIZE 64
    #define BUF_SIZE 1024
    #define QUEUE_LENGTH 100

    typedef struct coord_s {
        int x;
        int y;
    } coord_t;

    typedef struct resources_s
    {
        int food;
        int linemate;
        int deraumere;
        int sibur;
        int mendiane;
        int phiras;
        int thystame;
    } resources_t;

    typedef struct egg_s {
        int id;
        int x;
        int y;
        struct egg_s *next;
    } egg_t;

    typedef struct player_s {
        int id;
        int life;
        int pos_x;
        int pos_y;
        int level;
        int direction;
        bool dead;
        bool ejected;
        bool incantating;
        bool fork;
        resources_t *rsc;
        struct player_s *next;
    } player_t;

    typedef struct team_s {
        char *name;
        player_t *players;
        int authorized_cli_nb;
        int nb_clients;
        egg_t *eggs;
        int nb_eggs;
        struct team_s *next;
    } team_t;

    typedef struct map_s {
        int width;
        int height;
        resources_t **rsc;
    } map_t;

    typedef struct client_s {
        char *team;
        int number;
        int socket;
        int nb_request;
        int connected;
        struct player_s *player;
        struct client_s *next;
    } client_t;

    typedef struct game_s {
        int nb_teams;
        team_t *teams;
        map_t *map;
        float frequency;
        int spawn;
    } game_t;

    typedef struct queue_s {
        client_t *client;
        int freq;
        int base_freq;
        bool first;
        char *command;
        struct queue_s *next;
    } queue_t;

    typedef struct init_s {
        int port;
        int authorized_cli_nb;
        int teams_nb;
        int width;
        int height;
        int last_id;
        float frequency;
        char *team_names[20];
        int ac_pos;
    } init_t;

    typedef struct server_s {
        bool stop;
        bool start;
        int socket;
        int max_socket;
        int nb_clients;
        int client_num;
        fd_set readfds;
        socklen_t addrlen;
        struct timeval timeout;
        struct sockaddr_in addr;
        struct sockaddr_in clientaddr;
        game_t *game;
        init_t *init;
        client_t *client;
        queue_t *queue;
    } server_t;

    void reply(server_t *server);
    void receive_msg(server_t *server);
    void wrong_or_unknown_command(client_t *client);
    void check_for_name(server_t *server, client_t *client, char *name);
    void parse_command(server_t *server, client_t *client, char *command);
    client_t *find_client_from_socket(server_t *server, int socket);
    void send_msg_gui(server_t *server, char *msg);

#endif /* !SERVER_H_ */
