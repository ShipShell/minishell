NAME = minishell
CFLAG = -g3 -fsanitize=address #-Wall -Wextra -Werror
SRC_NAME = main \
		parsing/parser \
		parsing/substitute \
		tester/tester \
		utils/utils \
		error/error \
		exec/exec_cd \
		exec/exec_command \
		exec/exec_echo \
		exec/exec_env \
		exec/exec_exit \
		exec/exec_export \
		exec/exec_pwd \
		exec/exec_unset \
		exec/exec_not_builtin \
		pipe

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
