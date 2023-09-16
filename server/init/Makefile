##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

SRC	=	init.c \
		parse/check_input.c \
		parse/server_help.c \
		parse/parse.c \
		parse/parse_names.c \
		parse/parse_values.c \
		parse/parse_window.c \
		parse/init_parser.c \
		teams/client.c \
		server/init_server.c \
		server/new_connection.c \
		server/setup_reads.c \

LIB_NAME = libinit.a

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
