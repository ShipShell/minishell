.SUFFIXEX : .c .o

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AFLAGS = rc

FILES =	ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putchar \
		ft_putstr \
		ft_nbrlen \
		ft_strcmp \
		ft_lstnew \
  		ft_lstadd_front \
  		ft_lstsize \
  		ft_lstlast \
  		ft_lstadd_back \
  		ft_lstdelone \
  		ft_lstclear \
  		ft_lstiter \
  		ft_lstmap

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	ar $(AFLAGS) $@ $^

bonus : $(OBJS_B)
	ar $(AFLAGS) $(NAME) $^

all : $(NAME)

clean :
	rm -rf $(OBJS) $(OBJS_B)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
