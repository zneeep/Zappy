/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server_help
*/

#include "init.h"

void print_help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height");
    printf(" -n name1 name2 ... -c clientsNb -f freq\n\t");
    printf("port\tis the port number\n\t");
    printf("width\tis the width of the world\n\t");
    printf("height\tis the height of the world\n\t");
    printf("nameX\tis the name of the team X\n\t");
    printf("clientsNb\tis the number of authorized clients per team\n\t");
    printf("freq\tis the reciprocal of time unit for execution of actions\n");
}

void get_help(char *arg)
{
    if (!strcmp(arg, "-help")) {
        print_help();
        exit(0);
    }
    return;
}
