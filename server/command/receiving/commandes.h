/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** commandes
*/

#ifndef check_H_
    #define check_H_

    #include "game.h"

    const list_t commands[] = {
        {"GRAPHIC", 0, "connect graphique client"},
        {"msz", 0, "map size"},
        {"bct", 0, "content of a tile"},
        {"mct", 0, "content of all map"},
        {"tna", 0, "name of all the teams"},
        {"ppo", 0, "player's position"},
        {"plv", 0, "player's level"},
        {"pin", 0, "player's inventory"},
        {"sgt", 0, "time unit request"},
        {"sst", 0, "time unit modification"},
        {"Set", 7, "Set object"},
        {"Left", 7, "Move Left"},
        {"Look", 7, "Look"},
        {"Take", 7, "Take object"},
        {"Fork", 42, "Fork"},
        {"Right", 7, "Move Right"},
        {"Eject", 7, "Eject"},
        {"Forward", 7, "Move Forward"},
        {"Inventory", 1, "Get Inventory"},
        {"Connect_nbr", 0, "Connect number"},
        {"Incantation", 300, "Incantation"},
        {"Broadcast", 7, "Broadcast text"},
        {NULL, 0, NULL},
    };

#endif /* !check_H_ */
