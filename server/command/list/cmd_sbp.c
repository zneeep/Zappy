/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_sbp
*/

#include "game.h"

void sbp_cmd(client_t *client, server_t *server, char *str)
{
    char *msg = NULL;

    msg = calloc(1, sizeof(char) * 20);
    sprintf(msg, "sbp\n");
    send_msg_gui(server, msg);
    free(msg);
}
