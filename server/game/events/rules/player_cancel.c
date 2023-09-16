/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** player_cancel
*/

#include "game.h"

void eject_effect(client_t *client)
{
    client_t *c = client;

    while (c) {
        if (c->player && c->player->incantating && c->player->ejected) {
            c->player->incantating = false;
            send_msg(c->socket, "ko\n");
        }
        if (c->player && c->player->fork && c->player->ejected) {
            c->player->incantating = false;
            send_msg(c->socket, "ko\n");
        }
        c = c->next;
    }
}
