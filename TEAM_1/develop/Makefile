NAME = minishell
CFLAG = -Wall -Wextra -Werror
SRC_NAME = main \
		main_sub \
		parsing/add_redir \
		parsing/cmd_to_tokens \
		parsing/input_to_cmd \
		parsing/quoting \
		parsing/redirection \
		parsing/substitute \
		parsing/substitute2 \
		parsing/substitute3 \
		parsing/substitute4 \
		tester/tester \
		utils/utils \
		utils/utils2 \
		error/error \
		error/error2 \
		error/syntax_error \
		error/syntax_error2 \
		exec/exec_cd \
		exec/exec_command \
		exec/exec_command_sub \
		exec/exec_echo \
		exec/exec_env \
		exec/exec_exit \
		exec/exec_export \
		exec/exec_export2 \
		exec/exec_pwd \
		exec/exec_unset \
		exec/exec_not_builtin \
		exec/pipe \
		exec/pipe2 \
		exec/redirection \
		exec/util_exec \
		prompt/prompt \

SRC = $(addprefix src/,$(addsuffix .c, $(SRC_NAME)))
SRCDIR = ./src
INCLUDE = -I ./include -I ./libft/include
LIBFT = libft.a
LIBFT_DIR = ./libft
MAKE = make

all : $(NAME)

clean :
	rm -rf minishell.dSYM
fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
re : fclean all

bonus : all

run : all
	./minishell
test :
	gcc -o tester $(CFLAGS) src/utils.c src/parser.c src/tester.c src/unit_tester.c -I ./include -I ./libft/include -L./libft -lft
	./tester

$(NAME) : $(SRC) $(LIBFT_DIR)/$(LIBFT)
	gcc $(CFLAG) -o $@ $(SRC) -L $(LIBFT_DIR) -lft $(INCLUDE)

$(LIBFT_DIR)/$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) all clean
.PONY : all clean fclean re bonus run
