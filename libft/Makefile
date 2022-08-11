SRCS = ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_isalpha.c 	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c 	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c 	\
		ft_striteri.c  	\
		$(GET_NEXT_LINE_SRCS)

SRCSB =	ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		$(SRCS)

PRINTF_DIR = ft_printf/
PRINTF_LIB = libftprintf.a

GET_NEXT_LINE_SRCS = get_next_line_bonus.c \
					 get_next_line_utils_bonus.c

NAME = libft.a

HEADER_PATH = .

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

OBJSB = $(SRCSB:.c=.o)
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJSB))

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

#text color
COLOR_OFF =\033[0m
RED =\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
CYAN=\033[0;36m

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "$(YELLOW)Compiling: $<$(COLOR_OFF)"
	@$(CC) $(CFLAGS) -c -I$(HEADER_PATH) $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar rcs $(NAME) $(OBJECTS_PREFIXED) 
	@make -C $(PRINTF_DIR)
	@cp $(PRINTF_DIR)$(PRINTF_LIB) $(NAME)
	@echo "$(GREEN)libft Done !$(COLOR_OFF)"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(PRINTF_DIR)$(PRINTF_LIB)

re: fclean all

bonus: $(OBJECTS_BONUS_PREFIXED)
	@ar rcs $(NAME) $(OBJECTS_BONUS_PREFIXED)
	@make -C $(PRINTF_DIR)
	@cp $(PRINTF_DIR)$(PRINTF_LIB) $(NAME)
	@echo "$(GREEN)libft Bonus Done !$(COLOR_OFF)"
