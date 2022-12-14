NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main_mandatory.c \
	pipex_init.c \
	pipex_child.c \
	pipex_cmd.c \
	pipex_error.c \
	pipex_free.c \
	pipex_path.c

BONUS_SRCS = main_bonus.c \
	file_bonus.c \
	here_doc_bonus.c \
	pipex_child_bonus.c \
	pipex_cmd_bonus.c \
	pipex_error_bonus.c \
	pipex_free_bonus.c \
	pipex_init_bonus.c \
	pipex_path_bonus.c

SRCS_PREFIXED = $(addprefix mandatory/srcs/, $(SRCS))
BONUS_SRCS_PREFIXED = $(addprefix bonus/srcs/, $(BONUS_SRCS))

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
	@mkdir -p $(OBJS_DIR)
	@(CC) (CFLAGS) -I. -c $< -o $@

$(NAME) : $(LIBFT_LIB) 
	@$(CC) $(CFLAGS) -Imandatory/includes $(SRCS_PREFIXED) $(LIBFT_DIR)$(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)pipex.exe Done!$(COLOR_OFF)"

bonus: $(LIBFT_LIB)
	@$(CC) $(CFLAGS) -Ibonus/includes $(BONUS_SRCS_PREFIXED) $(LIBFT_DIR)$(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)(bonus) pipex.exe Done!$(COLOR_OFF)"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Removed : obj files ($(NAME))$(COLOR_OFF)"
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed : $(NAME).exe$(COLOR_OFF)"
	@rm -rf libft/libft.a
	@echo "$(RED)Removed : libft.a$(COLOR_OFF)"
	@rm -rf libft/ft_printf/libftprintf.a
	@echo "$(RED)Removed : libftprinf.a$(COLOR_OFF)"

re : fclean all

.PHONY : all bonus clean fclean re test heredoc

# Test your commands here.

# Mandatory = write two commands only.
IN = in.txt
OUT = out.txt

# Bonus = define your limiter here.
LIMITER = eof

# Mandatory = write 2 commands only.
# Bonus = write as many commands as you like.
TEST_CMDS = cat cat cat cat

test:
	./pipex $(IN) $(TEST_CMDS) $(OUT) && cat $(OUT)

heredoc:
	./pipex here_doc $(LIMITER) $(TEST_CMDS) $(OUT) && cat $(OUT)
