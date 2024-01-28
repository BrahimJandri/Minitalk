NAME = server client
B_NAME = server_bonus client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF = ft_printf/libftprintf.a
CFILE = server.c client.c
B_FILE = server_bonus.c client_bonus.c

all:$(NAME)

$(NAME): $(CFILE) $(FT_PRINTF)
	$(CC) $(CFLAGS) server.c $(FT_PRINTF) -o server
	$(CC) $(CFLAGS) client.c $(FT_PRINTF) -o client

$(B_NAME): $(B_FILE) $(FT_PRINTF)
	$(CC) $(CFLAGS) server_bonus.c $(FT_PRINTF) -o server_bonus
	$(CC) $(CFLAGS) client_bonus.c $(FT_PRINTF) -o client_bonus

$(FT_PRINTF):
	$(MAKE) -C ./ft_printf

bonus:$(B_NAME)

clean:
	$(MAKE) -C ./ft_printf clean

fclean: clean
	rm -rf $(NAME) $(B_NAME)
	$(MAKE) -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
