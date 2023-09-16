/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** tile_rsc
*/

#include "game.h"

void get_tile_deraumere(char **buf, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (!(*buf)) {
            (*buf) = calloc(1, sizeof(char) * 11);
            strcpy((*buf), "deraumere");
        } else {
            size_t len = strlen(*buf);
            (*buf) = realloc((*buf), sizeof(char) * (len + 11));
            strcat((*buf), " deraumere");
        }
    }
}

void get_tile_food(char **buf, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (!(*buf)) {
            (*buf) = calloc(1, sizeof(char) * 6);
            strcpy((*buf), "food");
        } else {
            size_t len = strlen(*buf);
            (*buf) = realloc((*buf), sizeof(char) * (len + 6));
            strcat((*buf), " food");
        }
    }
}

void get_tile_linemate(char **buf, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (!(*buf)) {
            (*buf) = calloc(1, sizeof(char) * 10);
            strcpy((*buf), "linemate");
        } else {
            size_t len = strlen(*buf);
            (*buf) = realloc((*buf), sizeof(char) * (len + 10));
            strcat((*buf), " linemate");
        }
    }
}

void get_tile_mendiane(char **buf, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (!(*buf)) {
            (*buf) = calloc(1, sizeof(char) * 10);
            strcpy((*buf), "mendiane");
        } else {
            size_t len = strlen(*buf);
            (*buf) = realloc((*buf), sizeof(char) * (len + 10));
            strcat((*buf), " mendiane");
        }
    }
}

void get_tile_phiras(char **buf, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (!(*buf)) {
            (*buf) = calloc(1, sizeof(char) * 8);
            strcpy((*buf), "phiras");
        } else {
            size_t len = strlen(*buf);
            (*buf) = realloc((*buf), sizeof(char) * (len + 8));
            strcat((*buf), " phiras");
        }
    }
}
