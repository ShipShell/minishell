NAME = minishell
CFLAG = #-Wall -Wextra -Werror -g3 -fsanitize=address
SRC_NAME = main
SRC = $(addprefix src/,$(addsuffix .c, $(SRC_NAME)))
SRCDIR = ./src
INCLUDE = -I ./include
LIBFT = libft.a
LIBFT_DIR = ./libft
MAKE = make

all : $(NAME)

clean :

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
re : fclean all

bonus : all

run : all
	export PATH=$(PATH):$(PWD)
	./minishell

$(NAME) : $(SRC) $(LIBFT_DIR)/$(LIBFT)
	gcc $(CFLAG) -o $@ $(SRC) -L $(LIBFT_DIR) -lft $(INCLUDE)

$(LIBFT_DIR)/$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) all clean
.PONY : all clean fclean re bonus run
