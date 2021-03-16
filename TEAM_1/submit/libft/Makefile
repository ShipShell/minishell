#.SUFFIXEX : .c .o
NAME = libft.a
CC = gcc
AFLAGS = rc
INCLUDE = -I./include
CFLAGS = -Wall -Wextra -Werror
SRCDIR = ./src
OBJDIR = ./obj
SRCNAME = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strndup.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_uitoa.c \
		ft_ultoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_ltoa.c \
		ft_ltoa_base.c \
		ft_itoa_base.c \
		ft_uitoa_base.c \
		ft_ultoa_base.c \
		ft_strchr_only.c \
		ft_signifi_figure.c \
		ft_pow.c \
		ft_intlen.c \
		ft_needle.c \
		get_next_line.c \
		ft_printf.c \
		ft_align.c \
		ft_conv.c \
		ft_dtoa_init.c \
		ft_dtoa_rounding.c \
		ft_dtoa_trans.c \
		ft_dtoa.c \
		ft_flag_symbol.c \
		ft_get_data_1.c \
		ft_get_data_2.c \
		ft_get_data_length.c \
		ft_parse_sub.c \
		ft_precision.c \
		ft_star.c \
		ft_putstr.c \
		ft_strcmp.c \
		ft_putchar.c

SRCS = $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))

all : $(NAME)

clean :
	rm -rf $(OBJECTS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

$(NAME) : $(OBJECTS)
	ar $(AFLAGS) $@ $?
$(OBJDIR)/%.o : $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $? -o $@ $(INCLUDE)
.PHONY : all clean fclean re
