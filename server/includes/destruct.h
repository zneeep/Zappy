/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** destruct
*/

#ifndef DESTRUCT_H_
    #define DESTRUCT_H_

    #include "server.h"

    struct server_t;
    struct client_t;

    void server_destroy(void);
    void destroy(server_t *server);
    void destroy_teams(team_t *team);
    void destroy_player(player_t *player);
    void destroy_players(player_t *player);
    void init_destroy(server_t *server);
    void game_destroy(server_t *server);
    void client_destroy(server_t *server);

    void renit_client_values(client_t *client);

    void disconnect_client(server_t *server, client_t *client);
    void remove_client_queue_cmd(server_t *server, client_t *client);
    void remove_client_from_team(team_t *team);

#endif /* !DESTRUCT_H_ */
