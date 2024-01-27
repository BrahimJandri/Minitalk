NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

SRC = ft_printf.c ft_printf_char.c ft_printf_hexlow.c ft_printf_hexupp.c \
	ft_printf_str.c ft_printf_int.c ft_printf_unsigned.c ft_printf_add.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean
