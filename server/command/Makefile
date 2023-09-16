##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

SRC	=	receiving/receive.c \
		receiving/parse.c \
		receiving/check_new_client.c \
		replys/reply.c \
		replys/queue.c \
		replys/rsc_management.c \
		list/cmd_graphic.c \
		list/cmd_msz.c \
		list/cmd_bct.c \
		list/cmd_mct.c \
		list/cmd_tna.c \
		list/cmd_pnw.c \
		list/cmd_ppo.c \
		list/cmd_plv.c \
		list/cmd_pin.c \
		list/cmd_pex.c \
		list/cmd_pbc.c \
		list/cmd_pic.c \
		list/cmd_pie.c \
		list/cmd_pfk.c \
		list/cmd_pdr.c \
		list/cmd_pgt.c \
		list/cmd_pdi.c \
		list/cmd_enw.c \
		list/cmd_ebo.c \
		list/cmd_edi.c \
		list/cmd_sgt.c \
		list/cmd_sst.c \
		list/cmd_seg.c \
		list/cmd_seg.c \
		list/cmd_smg.c \
		list/cmd_suc.c \
		list/cmd_sbp.c \
		list/cmd_inv.c \
		list/cmd_set.c \
		list/cmd_left.c \
		list/cmd_look.c \
		list/cmd_brad.c \
		list/cmd_take.c \
		list/cmd_fork.c \
		list/cmd_right.c \
		list/cmd_eject.c \
		list/cmd_eject_2.c \
		list/cmd_invoc.c \
		list/cmd_co_nbr.c \
		list/cmd_forward.c \

LIB_NAME = libcmd.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -I../includes

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
