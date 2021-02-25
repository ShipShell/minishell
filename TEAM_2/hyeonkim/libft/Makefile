# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 11:28:33 by hyeonkim          #+#    #+#              #
#    Updated: 2021/01/13 15:13:07 by hyeonkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 	= gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isdouble.c\
			ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
			ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_atod.c ft_strndup.c\
			get_next_line.c\

BNS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS = $(SRCS:%.c=%.o)

BNS_OBJS = $(BNS_SRCS:%.c=%.o)

$(NAME) : 
		@$(CC) $(CFLAGS) -c $(SRCS) -I ./ -D BUFFER_SIZE=1
		@ar rc $(NAME) $(OBJS)

all : $(NAME)

bonus : $(NAME)
		@$(CC) $(CFLAGS) -c $(BNS_SRCS) -I ./
		@ar rc $(NAME) $(BNS_OBJS)

clean :
		@rm -f $(OBJS) $(BNS_OBJS)

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus