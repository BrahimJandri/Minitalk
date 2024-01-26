NAME := Minitalk
FUNC := server.c client.c
CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar rcs
RM := rm -rf


CLIENT = client
SERVER = server

all: $(NAME)

$(SERVER):	$(SERVER).c minitalk.h 
		$(CC) $(CFLAGS) -o $(SERVER) $(SERVER).c

$(CLIENT):	$(CLIENT).c minitalk.h
		$(CC)	$(CFLAGS)	-o	$(CLIENT)	$(CLIENT).c

$(NAME):	$(SERVER) $(CLIENT)

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re