/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** check_ebo
*/

#include "game.h"

void ebo_cmd(client_t *client, server_t *server, char *str)
{
    send_msg_gui(server, str);
}
