##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
LDFLAGS = -Ldestruction -Lgame -Linit -Lcommand
LIBS = -ldestruction -lgame -linit -lcmd

OBJ_FILES = server.o
LIB_FILES = destruction/libdestruction.a game/libgame.a init/libinit.a \
			command/libcmd.a tools/libtools.a

NAME = zappy_server

.PHONY: all clean fclean

all: server

server: $(OBJ_FILES) $(LIB_FILES)
	@$(CC) $(LDFLAGS) $^ -o $(NAME) $(LIBS)

destruction/libdestruction.a:
	@cd destruction && $(MAKE) -s

game/libgame.a:
	@cd game && $(MAKE) -s

init/libinit.a:
	@cd init && $(MAKE) -s

command/libcmd.a:
	@cd command && $(MAKE) -s

tools/libtools.a:
	@cd tools && $(MAKE) -s

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES) $(LIB_FILES)
	@cd destruction && $(MAKE) clean -s
	@cd game && $(MAKE) clean -s
	@cd init && $(MAKE) clean -s
	@cd command && $(MAKE) clean -s
	@cd tools && $(MAKE) clean -s

fclean:
	@rm -f $(OBJ_FILES) $(LIB_FILES)
	@rm -f $(NAME)
	@cd destruction && $(MAKE) fclean -s
	@cd game && $(MAKE) fclean -s
	@cd init && $(MAKE) fclean -s
	@cd command && $(MAKE) fclean -s
	@cd tools && $(MAKE) clean -s
