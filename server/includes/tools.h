/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** tools
*/

#ifndef TOOLS_H_
    #define TOOLS_H_

    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    int get_size_tab(char *str, char delim);
    char *get_arg(char *line, char delim);
    char *get_first_arg(char *name, char delim);
    char **get_args(char **tab, char *buf, char *separators);
    char **get_tab(char **tab, char *str, char delim);
    char *my_strdup(const char *str);

    void free_double_ptr(char **value);

    void send_msg(int socket, char *msg);

#endif /* !TOOLS_H_ */
