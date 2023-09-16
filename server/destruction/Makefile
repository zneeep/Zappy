##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

SRC	=	destruction.c \
		server/server.c \
		server/init.c \
		team/disconnexion.c \
		team/client.c \
		team/team.c \
		game/queue.c \
		game/game.c \

LIB_NAME = libdestruction.a

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
