CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= minitalk.a
CLIENT	= client.c
SERVER	= server.c

all: library $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(CLIENT) $(NAME) -o client
	$(CC) $(CFLAGS) $(SERVER) $(NAME) -o server

library:
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)

clean:
	make clean -C libft

fclean: clean
	$(RM) $(NAME) client server
	make fclean -C libft

re: fclean all

.PHONY: all $(NAME) library clean fclean re