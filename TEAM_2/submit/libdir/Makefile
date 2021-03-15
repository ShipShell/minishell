NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
FILES = ft_memset \
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
		ft_strcmp \
		ft_strndup \
		get_next_line \
		get_next_line_utils


FILES_B = 	ft_lstnew \
	  		ft_lstadd_front \
	  		ft_lstsize \
	  		ft_lstlast \
	  		ft_lstadd_back \
	  		ft_lstdelone \
	  		ft_lstclear \
	  		ft_lstiter \
	  		ft_lstmap\

FILES_C =	checking	\
			ft_printf		\
			cd_printing	\
			us_printing	\
			xp_printing	\
			ls_printing	\
			per_printing	\
			f_printing	\
			xp_printing2	\
			putfunc		\
			n_printing	\
			f_printing2	\
			util

SRCS_DIR = ./
PRINTF_DIR = ./printf_src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))
SRCS_C = $(addprefix $(PRINTF_DIR), $(addsuffix .c, $(FILES_C)))
OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))
OBJS_C = $(addprefix $(PRINTF_DIR), $(addsuffix .o, $(FILES_C)))
all: $(NAME)
.c.o: $(SRCS) $(SRCS_B) $(SRCS_C)
	@$(CC) $(CFLAGS) -I ./ -c -o $@ $<
$(NAME): $(OBJS) $(OBJS_B) $(OBJS_C)
	@$(AR) $@ $^
bonus: $(OBJS_B)
	@$(AR) $(NAME) $^
clean:
	@$(RM) $(OBJS) $(OBJS_B) $(OBJS_B) $(OBJS_C)
fclean: clean
	@$(RM) $(NAME)
re: clean all
.PHONY: bonus all clean fclean re
