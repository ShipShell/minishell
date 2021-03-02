NAME = minishell
CFLAG = -g3 -fsanitize=address #-Wall -Wextra -Werror
SRC_NAME = *
SRC = $(addprefix src/,$(addsuffix .c, $(SRC_NAME)))
SRCDIR = ./src
INCLUDE = -I ./include -I ./libft/include
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
	./minishell

$(NAME) : $(SRC) $(LIBFT_DIR)/$(LIBFT)
	gcc $(CFLAG) -o $@ $(SRC) -L $(LIBFT_DIR) -lft $(INCLUDE)

$(LIBFT_DIR)/$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) all clean
.PONY : all clean fclean re bonus run
