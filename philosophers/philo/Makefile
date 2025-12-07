CC = cc 
CFLAGS = -pthread -Wall -Werror #-g3 -fsanitize=thread  #-fsanitize=undefined
SRCS = philos.c   init.c activities.c housekeepers.c threads.c time.c init2.c eat.c thread.c
HEADER = philos.h 

OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
