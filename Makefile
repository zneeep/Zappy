# Makefile for zappy_ai, zappy_server, and zappy_gui

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

.PHONY: all ai server gui clean

# Default target
all: ai server gui

re: fclean all

# Build and move zappy_ai binary
ai:
	@echo -e "${GREEN}Building zappy_ai binary...${NC}"
	cd ai && make
	mv ai/zappy_ai .

# Build and move zappy_server binary
server:
	@echo -e "${GREEN}Building zappy_server binary...${NC}"
	cd server && make
	mv server/zappy_server .

# Build and move zappy_gui binary
gui:
	@echo -e "${GREEN}Building zappy_gui binary...${NC}"
	cd gui && cmake . && make
	mv gui/zappy_gui .

# Clean generated binaries
clean:
	@cd server && $(MAKE) clean -s
fclean:
	rm -f zappy_ai zappy_server zappy_gui
	@cd server && $(MAKE) fclean -s
# Completion message
completion:
	@echo -e "${YELLOW}Build process completed.${NC}"
