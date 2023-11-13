NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
OBJDIR = obj
SOURCES = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c ft_printf.c print_characters.c \
	print_hexes.c print_numbers.c
BSOURCES = \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
BOBJECTS = $(addprefix $(OBJDIR)/, $(BSOURCES:.c=.o))

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)
	@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

$(NAME): $(OBJECTS)
	@ar -rc $@ $?
	@echo "$(YELLOW)Compiling libft...$(DEF_COLOR)"

bonus: $(OBJECTS) $(BOBJECTS)
	@ar -r $(NAME) $?
	@echo "$(GREEN)Bonus libft compiled!$(DEF_COLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc -c $(CFLAGS) $< -o $@
	@echo "$(CYAN)Compiling $<...$(DEF_COLOR)"

$(shell if [ ! -d "$(OBJDIR)" ]; then mkdir -p $(OBJDIR); fi)

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)Object files removed!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Libft removed!$(DEF_COLOR)"

re: fclean all

.PHONY: all bonus clean fclean re