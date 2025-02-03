NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Library path for libft.a
LIBFT_DIR = mylib
LIBFT = $(LIBFT_DIR)/lib/libft.a

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRC_SERVER) $(LIBFT)

$(NAME_CLIENT): $(SRC_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRC_CLIENT) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(LIBFT)

re: fclean all
