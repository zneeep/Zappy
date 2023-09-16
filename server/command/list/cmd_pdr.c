/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_pdr
*/

#include "game.h"

void pdr_cmd(client_t *client, server_t *server, char *str)
{
    send_msg_gui(server, str);
}
