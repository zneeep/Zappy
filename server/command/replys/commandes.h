/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** commandes
*/

#ifndef cmds_H
    #define cmds_H

    #include "game.h"

    const cmd_t cmds[] = {
        {"suc", 0, (void (*)())&suc_cmd},
        {"ppo", 0, (void (*)())&ppo_cmd},
        {"plv", 0, (void (*)())&plv_cmd},
        {"pin", 0, (void (*)())&pin_cmd},
        {"tna", 0, (void (*)())&tna_cmd},
        {"bct", 0, (void (*)())&bct_cmd},
        {"mct", 0, (void (*)())&mct_cmd},
        {"msz", 0, (void (*)())&msz_cmd},
        {"sgt", 0, (void (*)())&sgt_cmd},
        {"sst", 0, (void (*)())&sst_cmd},
        {"seg", 0, (void (*)())&seg_cmd},
        {"Set", 7, (void (*)())&set_cmd},
        {"Left", 7, (void (*)())&left_cmd},
        {"Look", 7, (void (*)())&look_cmd},
        {"Fork", 42, (void (*)())&fork_cmd},
        {"Take", 7, (void (*)())&take_cmd},
        {"Right", 7, (void (*)())&right_cmd},
        {"Eject", 7, (void (*)())&eject_cmd},
        {"Forward", 7, (void (*)())&forward_cmd},
        {"Inventory", 1, (void (*)())&inv_cmd},
        {"Incantation", 300, (void (*)())&invoc_cmd},
        {"Broadcast", 7, (void (*)())&brad_cmd},
        {NULL, 0, NULL},
    };

        const check_t cmd_check[] = {
        {"msz", 0, (bool (*)())&check_msz, "map size"},
        {"bct", 0, (bool (*)())&check_bct, "content of a tile"},
        {"mct", 0, (bool (*)())&check_mct, "content of all map"},
        {"tna", 0, (bool (*)())&check_tna, "name of all the teams"},
        {"ppo", 0, (bool (*)())&check_ppo, "player's position"},
        {"plv", 0, (bool (*)())&check_plv, "player's level"},
        {"pin", 0, (bool (*)())&check_pin, "player's inventory"},
        {"sgt", 0, (bool (*)())&check_sgt, "time unit request"},
        {"sst", 0, (bool (*)())&check_sst, "time unit modification"},
        {"Set", 7, (bool (*)())&check_set, "Set object"},
        {"Left", 7, (bool (*)())&check_left, "Move Left"},
        {"Look", 7, (bool (*)())&check_look, "Look"},
        {"Take", 7, (bool (*)())&check_take, "Take object"},
        {"Fork", 42, (bool (*)())&check_fork, "Fork"},
        {"Right", 7, (bool (*)())&check_right, "Move Right"},
        {"Eject", 7, (bool (*)())&check_eject, "Eject"},
        {"Forward", 7, (bool (*)())&check_forward, "Move Forward"},
        {"Inventory", 1, (bool (*)())&check_inv, "Get Inventory"},
        {"Connect_nbr", 0, (bool (*)())&check_co_nbr, "Connect number"},
        {"Incantation", 300, (bool (*)())&check_invoc, "Incantation"},
        {"Broadcast", 7, (bool (*)())&check_brad, "Broadcast text"},
        {NULL, 0, NULL, NULL},
    };

#endif /* !cmds_H */
