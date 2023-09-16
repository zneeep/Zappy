/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "server.h"

    #define NAME_SIZE 64

    typedef struct list_s {
        char *name;
        int freq;
        char *help;
    } list_t;

    typedef struct check_s {
        char *name;
        int freq;
        bool (*func)();
        char *help;
    } check_t;

    typedef struct cmd_s {
        char *name;
        int freq;
        void (*func)();
    } cmd_t;

    typedef void (*func_t)(game_t *, player_t *);

    // func

    resources_t modif_resources_cell(resources_t rsc,
    const char *type, int qty);
    resources_t modif_resources_cell_2(resources_t rsc,
    const char *type, int qty);
    resources_t modif_resources_cell_3(resources_t rsc,
    const char *type, int qty);
    int found_player_id_available(server_t *server, team_t *team);
    char *find_team_name_with_player_id(team_t *teams, int id);
    team_t *find_team_with_name(team_t *teams, const char *name);
    player_t *find_player_with_id_2(player_t *player, int id);
    player_t *find_player_with_id(team_t *teams, int id);
    player_t *find_player_with_co(player_t *player, int x, int y);
    void action_on_tile(client_t *client, game_t *game, func_t function);
    void action_on_egg(server_t *server, client_t *client, game_t *game);
    void remove_egg_from_list(team_t *team, egg_t *egg);
    void ressource_get(client_t *client, game_t *game, char *name, bool add);
    void ressource_manager(int *rsc_player, int *rsc_map, bool add);
    bool ressource_check(client_t *client, game_t *game, char *name, bool add);
    char *find_team_name_with_player_id(team_t *teams, int id);
    client_t *find_client_from_p_id(server_t *server, int id);
    void free_command(queue_t *queue);
    void get_next_command(server_t *server, queue_t *queue);
    bool check_cmd(server_t *server, queue_t *current);
    coord_t *get_vector(player_t *source, player_t *dest, int height,
    int width);
    int get_tile_from_co(coord_t *vector);
    bool check_level(server_t *server, resources_t rsc, player_t *player);
    bool check_incatation_tile(player_t *player, player_t *p);
    void map_resources_management(game_t *game);
    void set_player_invoc(server_t *server, int x, int y);
    void remove_player_invoc(server_t *server, int x, int y, char *str);

    void process_invalid_cmd(server_t *server, queue_t **c, queue_t **prv);
    void process_completed_cmd(server_t *server, queue_t **c, queue_t **prv);
    void call_command_queue(server_t *server, queue_t *current);

    void get_tile_food(char **buf, int nb);
    void get_tile_sibur(char **buf, int nb);
    void get_tile_phiras(char **buf, int nb);
    void get_tile_linemate(char **buf, int nb);
    void get_tile_mendiane(char **buf, int nb);
    void get_tile_thystame(char **buf, int nb);
    void get_tile_deraumere(char **buf, int nb);
    void get_tile_player(game_t *g, char **buf, int p_y, int p_x);

    coord_t *get_look_coord_0(game_t *g, player_t *p, int i, int j);
    coord_t *get_look_coord_1(game_t *g, player_t *p, int i, int j);
    coord_t *get_look_coord_2(game_t *g, player_t *p, int i, int j);
    coord_t *get_look_coord_3(game_t *g, player_t *p, int i, int j);

    // init

    bool init_game(server_t *server);
    bool init_teams(game_t *game, init_t *init);
    void create_all_teams(game_t *game, init_t *init);
    team_t *create_team_cell(init_t *init, int nb);
    void insert_new_team_at_end(team_t **head, init_t *init, int nb);
    void create_all_players(team_t *team, init_t *init, int nb);
    void insert_new_player_at_end(player_t **head, coord_t *coord,
    const int id);
    player_t *create_player_cell(coord_t *coord, const int id);
    bool init_map(game_t *game, init_t *init);
    void create_map(game_t *game);
    void init_resource_cell(game_t *game, const char *type, int qty);
    void init_resources_map(game_t *game);
    resources_t *declare_resources_player(void);
    egg_t *create_egg(int id, int x, int y);
    void insert_new_egg_at_end(team_t *team, int id, int x, int y);

    // destroy

    void destroy_player(player_t *player);

    // event

    void game_event(server_t *server);
    void player_life(team_t *team);
    void player_death(server_t *server, team_t *team);
    void eject_effect(client_t *client);

    // time

    void get_time(void);


    // commands

    void eject_player_0(game_t *game, player_t *player);
    void eject_player_1(game_t *game, player_t *player);
    void eject_player_2(game_t *game, player_t *player);
    void eject_player_3(game_t *game, player_t *player);

    bool check_graphic(server_t *server, client_t *client, char *command);
    bool check_msz(server_t *server, client_t *client, char *command);
    bool check_bct(server_t *server, client_t *client, char *command);
    bool check_mct(server_t *server, client_t *client, char *command);
    bool check_tna(server_t *server, client_t *client, char *command);
    bool check_ppo(server_t *server, client_t *client, char *command);
    bool check_plv(server_t *server, client_t *client, char *command);
    bool check_pin(server_t *server, client_t *client, char *command);
    bool check_sgt(server_t *server, client_t *client, char *command);
    bool check_sst(server_t *server, client_t *client, char *command);
    bool check_inv(server_t *server, client_t *client, char *command);
    bool check_set(server_t *server, client_t *client, char *command);
    bool check_left(server_t *server, client_t *client, char *command);
    bool check_look(server_t *server, client_t *client, char *command);
    bool check_fork(server_t *server, client_t *client, char *command);
    bool check_take(server_t *server, client_t *client, char *command);
    bool check_brad(server_t *server, client_t *client, char *command);
    bool check_right(server_t *server, client_t *client, char *command);
    bool check_eject(server_t *server, client_t *client, char *command);
    bool check_invoc(server_t *server, client_t *client, char *command);
    bool check_co_nbr(server_t *server, client_t *client, char *command);
    bool check_forward(server_t *server, client_t *client, char *command);

    void bct_bis_cmd(int socket, game_t *game, int x, int y);
    void graphic_cmd(server_t *server, client_t *client, int socket);
    void pfk_cmd(client_t *client, server_t *server, char *str);
    void co_nbr_cmd(server_t *server, int socket);
    void suc_cmd(client_t *client, server_t *server, char *str);
    void ppo_cmd(client_t *client, server_t *server, char *str);
    void plv_cmd(client_t *client, server_t *server, char *str);
    void pin_cmd(client_t *client, server_t *server, char *str);
    void tna_cmd(client_t *client, server_t *server, char *str);
    void bct_cmd(client_t *client, server_t *server, char *str);
    void mct_cmd(client_t *client, server_t *server, char *str);
    void msz_cmd(client_t *client, server_t *server, char *str);
    void sgt_cmd(client_t *client, server_t *server, char *str);
    void pex_cmd(client_t *client, server_t *server, char *str);
    void pdr_cmd(client_t *client, server_t *server, char *str);
    void inv_cmd(client_t *client, server_t *server, char *str);
    void set_cmd(client_t *client, server_t *server, char *str);
    void left_cmd(client_t *client, server_t *server, char *str);
    void look_cmd(client_t *client, server_t *server, char *str);
    void fork_cmd(client_t *client, server_t *server, char *str);
    void take_cmd(client_t *client, server_t *server, char *str);
    void brad_cmd(client_t *client, server_t *server, char *str);
    void right_cmd(client_t *client, server_t *server, char *str);
    void eject_cmd(client_t *client, server_t *server, char *str);
    void invoc_cmd(client_t *client, server_t *server, char *str);
    void forward_cmd(client_t *client, server_t *server, char *str);
    void pbc_cmd(client_t *client, server_t *server, char *str);
    void pic_cmd(client_t *client, server_t *server, char *str);
    void pie_cmd(client_t *client, server_t *server, char *str);
    void pdi_cmd(client_t *client, server_t *server, char *str);
    void enw_cmd(client_t *client, server_t *server, char *str);
    void ebo_cmd(client_t *client, server_t *server, char *str);
    void edi_cmd(client_t *client, server_t *server, char *str);
    void sst_cmd(client_t *client, server_t *server, char *str);
    void seg_cmd(client_t *client, server_t *server, char *str);
    void smg_cmd(client_t *client, server_t *server, char *str);
    void sbp_cmd(client_t *client, server_t *server, char *str);
    void pnw_cmd(client_t *client, server_t *server, char *str);
    void pgt_cmd(client_t *client, server_t *server, char *str);

#endif /* !GAME_H_ */
