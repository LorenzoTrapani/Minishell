NAME = minishell

CC = cc
INCLUDES = ./includes
CFLAGS = -Wextra -Werror -Wall -g -I$(INCLUDES)
COMPILE = $(CC) $(CFLAGS) -c
RM = rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a


GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC =	./src/main.c \
		./src/builtins/echo.c \
		./src/builtins/env.c \
		./src/builtins/exit.c \
		./src/builtins/export.c \
		./src/builtins/pwd.c \
		./src/builtins/unset.c \
		./src/builtins/cd.c \
		./src/executor/exec.c \
		./src/executor/input_dll.c \
		./src/executor/utils.c \
		./src/executor/free.c \
		./src/signal/signal_handle.c \

all: $(NAME)

$(LIBFT):
	make all -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(SRC)
	$(CC) $(CFLAGS) $(SRC) -L$(LIBFT_DIR) -lft -lreadline -o $(NAME)

	@echo "$(BLUE)	MINISHELL COMPILED!$(RESET)"

valgrind: $(NAME)
	valgrind --leak-check=full --show-reachable=yes --suppressions=readline.supp ./$(NAME)
	
clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all
.SILENT: