/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** check_input
*/

#include "init.h"

void check_input(server_t *server, int argc, char **argv)
{
    if (argc < 1)
        exit(84);
    if (argc == 2)
        get_help(argv[1]);
    parse(server, argc, argv);
}
