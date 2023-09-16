/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** my_strdup
*/

#include "tools.h"

char *my_strdup(const char *str)
{
    char *new_str = calloc(1, sizeof(char) * (strlen(str) + 1));
    strcpy(new_str, str);
    return new_str;
}
