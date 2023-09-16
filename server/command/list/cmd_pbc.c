/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_pbc
*/

#include "game.h"

void pbc_cmd(client_t *client, server_t *server, char *str)
{
    char *msg = NULL;

    msg = calloc(1, sizeof(char) * 50);
    sprintf(msg, "pbc %d%s\n", client->number, str);
    send_msg_gui(server, msg);
    free(msg);
}
