/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_edi
*/

#include "game.h"

void edi_cmd(client_t *client, server_t *server, char *str)
{
    char *msg = NULL;

    msg = calloc(1, sizeof(char) * 10);
    sprintf(msg, "edi %s\n", str);
    send_msg_gui(server, msg);
    free(msg);
}
