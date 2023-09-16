/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_suc
*/

#include "game.h"

void suc_cmd(client_t *client, server_t *server, char *str)
{
    send_msg_gui(server, "suc\n");
    printf("Unknow command\n");
}
