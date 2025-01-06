NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

LIBFT = libft.a

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRC_SERVER) $(LIBFT)

$(NAME_CLIENT): $(SRC_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRC_CLIENT) $(LIBFT)

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make -C libft clean
re: clean all

$(LIBFT):
	make -C libft
