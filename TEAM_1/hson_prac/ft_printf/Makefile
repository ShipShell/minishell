.SUFFIXEX : .c .o

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
AFLAGS = rc

SRCS_DIR = ./srcs/
SRCS_NAME =	ft_printf.c \
			print_char.c \
			print_str.c \
			print_integer.c \
			print_unsigned.c \
			utility.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))

OBJS_DIR = ./obj/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))

LIBFT_DIR = $(SRCS_DIR)/libft
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

INCLUDE = -I./include

$(NAME) : $(OBJS) $(LIBFT)
	cp $(LIBFT) $@
	$(AR) $(AFLAGS) $@ $(OBJS)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) all
$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

all : $(NAME)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re