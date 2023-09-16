D_SRC	=	./src/

NAME	=	zappy_ai

$(NAME): $(wildcard $(D_SRC)*.py)
		cp $(D_SRC)main.py $@
		chmod +x $@

all: $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re