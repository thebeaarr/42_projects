CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c parsing.c sorting.c utils1.c stack_utils1.c  stack_utils.c utils.c big_sort.c big_sort_help.c big_sort_help1.c big_sort_help2.c parsing_h.c sorting_h.c rotate.c push.c swap.c reverse_rotate.c 
HEADER = push_swap.h
NAME = push_swap
NAME1 = checker
OBJS = $(SRCS:.c=.o)
DIR_GET = get_next_line
HEADER_C  = $(DIR_GET)/get_next_line.h 
SRCS_B = $(DIR_GET)/get_next_line.c $(DIR_GET)/get_next_line_utils.c stack_utils.c parsing_c.c utils.c utils1.c my_checker.c stack_utils1.c rotate_c.c push_c.c swap_c.c reverse_rotate_c.c help.c parsing_c_h.c
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)


bonus: $(NAME1)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "making push_swap..."

$(NAME1):$(OBJS_B) $(HEADER_C) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME1)
	@echo "making checker..."
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(OBJS_B)
	@echo "clean object files"

fclean: clean
	@rm -rf $(NAME) $(NAME1)
	@echo "clean excutables"

re: fclean all
	@echo "remaking"

.PHONY: all clean fclean re
