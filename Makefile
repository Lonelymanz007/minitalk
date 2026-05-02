SERVER	= server
CLIENT	= client

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC_SRV	= server.c
OBJ_SRV	= $(SRC_SRV:.c=.o)

SRC_CLI	= client.c
OBJ_CLI	= $(SRC_CLI:.c=.o)

all: $(SERVER) $(CLIENT)


$(SERVER): $(OBJ_SRV)
	@$(CC) $(CFLAGS) $(OBJ_SRV) -o $(SERVER)

$(CLIENT): $(OBJ_CLI)
	@$(CC) $(CFLAGS) $(OBJ_CLI) -o $(CLIENT)

%.o: %.c $(HEADER)
	@printf "\033[1;92mCompiled 👌🏽 %s\033[0m\n" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "\033[1;31mRemoved object files 💣\033[0m\n"
	@rm -f $(OBJ_SRV) $(OBJ_CLI)

fclean: clean
	@rm -f $(SERVER) $(CLIENT)

re: fclean all
.PHONY: all clean fclean re