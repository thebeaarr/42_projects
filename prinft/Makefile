CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_itoa_utils.c ft_itoa.c ft_putchar_str.c fors.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
