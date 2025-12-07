CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories
MANDATORY_DIR = mandatory
BONUS_DIR = bonus
INC_DIR = includes
HELPER_DIR = helper
# Source files
SRCSC = $(MANDATORY_DIR)/client.c
SRCSS = $(MANDATORY_DIR)/server.c
SRCH = $(HELPER_DIR)/parse_pid.c $(HELPER_DIR)/add.c 
SRCSBONUSC = $(BONUS_DIR)/client_bonus.c
SRCSBONUSS = $(BONUS_DIR)/server_bonus.c

# Executable names
NAME = server
NAME1 = client
NAMEBONUS = server_bonus
NAME1BONUS = client_bonus

# Object files
OBJSC = $(SRCSC:.c=.o)
OBJSS = $(SRCSS:.c=.o)
OBJH = $(SRCH:.c=.o)
OBJSBONUSC = $(SRCSBONUSC:.c=.o)
OBJSBONUSS = $(SRCSBONUSS:.c=.o)

# Default target: build both server and client
all: $(NAME) $(NAME1)

# Rule to build the client executable
$(NAME1): $(OBJSC) $(OBJH)
	$(CC) $(OBJSC) $(OBJH) -o $(NAME1) $(CFLAGS)

# Rule to build the server executable
$(NAME): $(OBJSS) $(OBJH)
	$(CC) $(OBJSS) $(OBJH) -o $(NAME) $(CFLAGS)

# Bonus rule: build both bonus server and client
bonus: $(NAMEBONUS) $(NAME1BONUS)

# Rule to build the bonus client executable
$(NAME1BONUS): $(OBJSBONUSC) $(OBJH)
	$(CC) $(OBJSBONUSC) $(OBJH) -o $(NAME1BONUS) $(CFLAGS)

# Rule to build the bonus server executable
$(NAMEBONUS): $(OBJSBONUSS) $(OBJH)
	$(CC) $(OBJSBONUSS) $(OBJH) -o $(NAMEBONUS) $(CFLAGS)

# Pattern rule to compile .c files into .o files
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) -I $(INC_DIR)

# Clean rule to remove object files and executables
clean:
	rm -f $(OBJSC) $(OBJSS) $(OBJH) $(OBJSBONUSC) $(OBJSBONUSS)

# Rule to remove all generated files, including the executables
fclean: clean
	rm -f $(NAME) $(NAME1) $(NAMEBONUS) $(NAME1BONUS)

# Rebuild everything from scratch
re: fclean all
