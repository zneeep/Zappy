/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_pgt
*/

#include "game.h"

void pgt_cmd(client_t *client, server_t *server, char *str)
{
    send_msg_gui(server, str);
}
