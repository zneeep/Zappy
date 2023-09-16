/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_new_client
*/

#include "game.h"
#include "tools.h"
#include "init.h"

void add_client_to_team(team_t *teams, client_t *client, char *name, int id)
{
    client->team = calloc(1, sizeof(char) * (strlen(name) + 1));
    strcpy(client->team, name);
    printf("Client %d connected to team: %s\n", client->number, client->team);
    client->player = find_player_with_id(teams, id);
}

int connect_client_to_egg(server_t *server, client_t *client, team_t *team)
{
    egg_t *egg = team->eggs;
    coord_t *coord = calloc(1, sizeof(coord_t));

    if (!team || !team->eggs)
        return -1;
    coord->x = egg->x;
    coord->y = egg->y;
    insert_new_player_at_end(&team->players, coord, ++server->init->last_id);
    remove_egg_from_list(team, egg);
    free(egg);
    free(coord);
    return server->init->last_id;
}

bool set_client(server_t *server, team_t *team, client_t *client, char *name)
{
    int id = found_player_id_available(server, team);
    char *str_cmd = NULL;

    if (id < 0)
        id = connect_client_to_egg(server, client, team);
    add_client_to_team(server->game->teams, client, name, id);
    client->number = server->client_num++;
    client->nb_request = 0;
    client->connected = 1;
    str_cmd = calloc(1, sizeof(char) * 3);
    if (str_cmd != NULL) {
        sprintf(str_cmd, "%d", id);
        pnw_cmd(client, server, str_cmd);
        free(str_cmd);
    }
    return true;
}

void check_for_name(server_t *server, client_t *client, char *name)
{
    team_t *team = find_team_with_name(server->game->teams, name);
    char *msg = NULL;

    if (team == NULL || team->nb_clients >= team->authorized_cli_nb)
        return wrong_or_unknown_command(client);
    if (!set_client(server, team, client, name))
        return;
    msg = calloc(1, sizeof(char) * 20);
    int nb = team->authorized_cli_nb - team->nb_clients;
    sprintf(msg, "%d\n%d %d\n", nb, server->init->width, server->init->height);
    send_msg(client->socket, msg);
    team->nb_clients++;
    if (msg)
        free(msg);
}
