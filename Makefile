NAME = minishell

CC = cc
INCLUDES = ./includes
CFLAGS = -Wextra -Werror -Wall -g -I$(INCLUDES)
COMPILE = $(CC) $(CFLAGS) -c
RM = rm -f


LIBFT_DIR = ./libft.plus

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC =	./main.c \
		./src/builtins/echo.c \
		./src/builtins/env.c \
		./src/builtins/exit.c \
		./src/builtins/export.c \
		./src/builtins/export_utils.c \
		./src/builtins/pwd.c \
		./src/builtins/unset.c \
		./src/builtins/cd.c \
		./src/free_exit_handling/free_parsing.c \
		./src/lst_input_handling/dll_input_addback.c \
		./src/lst_input_handling/dll_input_addfront.c \
		./src/lst_input_handling/dll_input_clear.c \
		./src/lst_input_handling/dll_input_last.c \
		./src/lst_input_handling/dll_input_new.c \
		./src/lst_input_handling/dll_input_size.c \
		./src/parsing/expansion/expand_with_quotes.c \
		./src/parsing/expansion/expand.c \
		./src/parsing/expansion/get_env.c \
		./src/parsing/expansion/handling_env.c \
		./src/parsing/get_info/get_all_info.c \
		./src/parsing/get_info/get_args_mtx.c \
		./src/parsing/get_info/get_arr_token.c \
		./src/parsing/get_info/get_input_complete.c \
		./src/parsing/get_info/get_merged_line.c \
		./src/parsing/get_info/get_mtx_input.c \
		./src/parsing/handlers/handling_char.c \
		./src/parsing/handlers/handling_merge_flag.c \
		./src/parsing/handlers/handling_mtx_and_lists.c \
		./src/parsing/handlers/handling_quotes_as_word_token.c \
		./src/parsing/handlers/handling_token.c \
		./src/parsing/handlers/trim_quotes.c \
		./src/executor/exec_main.c \
		./src/executor/exec_utils.c \
		./src/executor/exec_free.c \
        ./src/executor/envp_utils.c \
		./src/executor/general_utils.c \
		./src/executor/redirect.c \
		./src/executor/redirect_utils.c

all: $(NAME)

$(NAME): $(SRC)
<<<<<<< HEAD
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I. -I$(INCLUDES) $(SRC) -L$(LIBFT_DIR) -lft -lreadline -o $(NAME)
=======
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I. -I$(INCLUDES) $(SRC) -L$(LIBFT_DIR) -lft -lreadline -o $(NAME)
>>>>>>> 5ea0f44f25636ebbd647aa0aa6499d45a3932a78
	@echo "$(BLUE)	MINISHELL COMPILED!$(RESET)"


valgrind: $(NAME)
	valgrind --leak-check=full -s --show-reachable=yes --suppressions=readline.supp ./$(NAME)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all
.SILENT: