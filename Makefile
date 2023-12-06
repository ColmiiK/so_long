#Variables

NAME = so_long
USER = alvega-g
INCLUDE = include
LIBFT = lib/libft
MLX42 = lib/MLX42
SRC_DIR = src/
B_SRC_DIR = src/bonus/
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
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
	
SRC_FILES = main map error_check utils window movement path sprites
B_SRC_FILES = main_bonus map_bonus error_check_bonus utils_bonus window_bonus movement_bonus path_bonus sprites_bonus enemies_bonus animation_bonus

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
B_SRC = $(addprefix $(B_SRC_DIR), $(addsuffix .c, $(B_SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
B_OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(B_SRC_FILES)))

###

OBJF = .cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@make -C $(MLX42)
			@$(CC) -I./$(INCLUDE) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
			@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -I./$(INCLUDE) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(B_SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -I./$(INCLUDE) $(CFLAGS) -c $< -o $@

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

bonus: $(B_OBJ)
			@make -C $(LIBFT)
			@make -C $(MLX42)
			@$(CC) $(CFLAGS) $(B_OBJ) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
			@echo "$(MAGENTA)so_long bonus compiled!$(DEF_COLOR)"

map:
			@./so_long maps/map_0.ber

.PHONY: all clean fclean re norm map bonus