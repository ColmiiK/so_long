#Variables

NAME = so_long
USER = alvega-g
INCLUDE = include
LIBFT = lib/libft
MLX42 = lib/MLX42
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES = main

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF = .cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@make -C $(MLX42)
			@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
			@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@make clean -C $(MLX42)
			@echo "$(CYAN)libft object files cleaned!$(DEF_COLOR)"
			@echo "$(BLUE)so_long object files cleaned!$(DEF_COLOR)"

fclean:		
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -f $(NAME)
			@make fclean -C $(LIBFT)
			@make fclean -C $(MLX42)
			@echo "$(CYAN)libft executable cleaned!$(DEF_COLOR)"
			@echo "$(BLUE)so_long executable cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(MAGENTA)so_long recompiled!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT)/src

.PHONY: all clean fclean re norm