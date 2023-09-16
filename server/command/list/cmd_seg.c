/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_seg
*/

#include "game.h"

void seg_cmd(client_t *client, server_t *server, char *str)
{
    char *msg = NULL;

    msg = calloc(1, sizeof(char) * 20);
    sprintf(msg, "seg %s\n", str);
    send_msg_gui(server, msg);
    free(msg);
}
