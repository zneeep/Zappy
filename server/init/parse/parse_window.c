/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** parse_window
*/

#include "init.h"

bool parse_check_height(server_t *server, char *str_height)
{
    int height = 0;

    if ((height = atoi(str_height)) <= 0)
        return false;
    server->init->height = height;
    return true;
}

bool parse_check_width(server_t *server, char *str_width)
{
    int width = 0;

    if ((width = atoi(str_width)) <= 0)
        return false;
    server->init->width = width;
    return true;
}
