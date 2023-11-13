NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft
LIBMLX_A := $(LIBMLX)/build/libmlx42.a
LIBFT_A := $(LIBFT)/libft.a
SRC_DIR := src/
OBJ_DIR := obj/

HEADERS	:= -I ./include -I $(LIBMLX) -I $(LIBFT)/include
LIBS	:= $(LIBMLX_A) $(LIBFT_A) -ldl -lglfw -L"/Users/alvega-g/.brew/opt/glfw/lib/" -pthread -lm
SRC_FILES	:= test

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft: $(LIBFT_A)

$(LIBFT_A):
	@make -C $(LIBFT)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJ) libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBFT)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx