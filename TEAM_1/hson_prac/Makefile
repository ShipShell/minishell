.SUFFIXEX : .c .o

NAME = minishell

CC = gcc
CFLAGS = #-Wall -Wextra -Werror #-g3 -fsanitize=address
LIBS_FLAGS = -Llibft -lft
INCLUDE = -I./ -I./libft

#SRCS_DIR = ./srcs/
#SRCS_NAME =	main.c \
			init.c \
			init_2.c \
			load_texture.c \
			free_or_error.c \
			free_or_error_2.c \
			get_next_line.c \
			parsing_cub_3.c \
			parse_line_3.c \
			parse_map_3.c \
			fill_map_3.c \
			check_map_valid_4.c \
			main_loop_5.c \
			cast_floor_ceiling_6.c \
			cast_wall_7.c \
			cast_sprite_8.c \
			sprite_sort_8.c \
			deal_key_9.c \
			control_player_10.c \
			bmp.c
#SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))

SRCS = cd.c \
		error.c

#OBJS_DIR = ./obj/
#OBJS_NAME = $(SRCS_NAME:.c=.o)
#OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(SRCS) $(LIBS_FLAGS) 

#$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
#		mkdir -p $(OBJS_DIR)
#		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(LIBFT) :
		$(MAKE) -C $(LIBFT_DIR) all clean

clean :

fclean : clean
#	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re : fclean all

run : $(NAME)
	./minishell

.PHONY : all clean fclean re