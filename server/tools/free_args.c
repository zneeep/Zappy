/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** free_args
*/

#include "tools.h"

void free_double_ptr(char **value)
{
    if (!value)
        return;
    for (int i = 0; value[i]; i++)
        if (value[i])
            free(value[i]);
    free(value);
}
