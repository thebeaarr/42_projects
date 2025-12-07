# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes
MLX_DIR = minilibx-linux

# File names
NAME = fractol
SRC_FILES = main.c fractals.c mlx_utils.c events.c zoom.c \
            burninship.c parse.c mandelbrot.c julia.c nichan.c \
			parse1.c \
			
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# MLX library
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -O3

# Default targetmak
all: $(NAME)

# Rule to create the object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Rule to link the executable
$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) -o $(NAME) $(MLX_LIB)
	@echo "✅ Build successful! Run './$(NAME)' to start."

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Cleaning object files..."

# Clean everything
fclean: clean
	@echo "🚨 Removing executable $(NAME)..."
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
