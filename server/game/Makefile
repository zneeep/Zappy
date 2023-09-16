##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

SRC	=	func/func.c \
		func/func_find_map.c \
		func/func_find_team.c \
		func/func_find_player.c \
		func/egg.c \
		func/tile_rsc.c \
		func/tile_rsc_bis.c \
		func/look_coords.c \
		func/get_bradcast_tile.c \
		func/check_level_up.c \
		func/set_player_invoc.c \
		init/init.c \
		init/init_egg.c \
		init/init_map.c \
		init/init_map_resources.c \
		init/init_team.c \
		init/init_player.c \
		time/time.c \
		events/rules/player_life.c \
		events/rules/player_cancel.c \
		events/rules/map_resources.c \
		events/game_event.c \

LIB_NAME = libgame.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I../includes

$(LIB_NAME): $(OBJ)
	@echo -e "\033[1;32mMaking lib ${LIB_NAME}\033[0m"
	@ar rcs $@ $^

all: $(LIB_NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	@echo -e "\033[1;31mCleaning ${LIB_NAME}\033[0m"
	rm -f $(LIB_NAME)
re: fclean all
