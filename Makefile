NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	pipex_init.c \
	pipex_child.c \
	pipex_cmd.c \
	pipex_error.c \
	pipex_free.c \
	pipex_path.c

OBJS_DIR = objs/
OBJS_M = $(SRCS:.c=.o)
OBJS_M_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS_M))

LIBFT_DIR = libft/
LIBFT_LIB = libft.a

#text color
COLOR_OFF =\033[0m
RED =\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
CYAN=\033[0;36m

all : $(NAME)

$(LIBFT_LIB) :
	@make bonus -C $(LIBFT_DIR)

$(OBJS_DIR)%.o : %.c
	@make -p $(OBJS_DIR)
	@(CC) (CFLAGS) -c $< -o $@

$(NAME) : $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT_DIR)$(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)pipex done!$(COLOR_OFF)"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Removed: obj files ($(NAME))$(COLOR_OFF)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed $(NAME)$(COLOR_OFF)"
	@make fclean -C $(LIBFT_DIR)

re : fclean all

test:
	make bonus -C libft
	gcc *.c libft/libft.a -o pipex && ./pipex in.txt "ls" "wc -l" out.txt && cat out.txt