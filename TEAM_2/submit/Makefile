# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 17:26:49 by hyeonkim          #+#    #+#              #
#    Updated: 2021/03/15 18:17:02 by hyeonkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAG = -Wall -Wextra -Werror
INCLUDE = -I./include -I./libdir
LIBDIR = ./libdir
LIBFT = libft.a
EXEC_SRCS = cd.c \
			cd2.c \
			echo.c \
			env.c \
			error.c \
			exec.c \
			exec2.c \
			exit.c \
			export.c \
			export2.c \
			export3.c \
			not_built_in.c \
			not_built_in2.c \
			pwd.c \
			redir.c \
			redir2.c \
			unset.c
PARSING_SRCS = check_syntax_error.c \
			check_syntax_error2.c \
			cmd_cycle.c \
			free.c \
			parse_cmd.c \
			quoting.c \
			replace1.c \
			replace2_check.c \
			replace3_replace.c \
			replace4_join.c \
			replace5_redirection.c \
			replace6_delete_quotes.c \
			replace6_utils.c \
			set_env.c \
			signal.c \
			tokenize.c \
			tokenize_utils.c

PARSING_DIR = ./srcs/parsing_srcs/
EXEC_DIR = ./srcs/exec_srcs/
PARSING = $(addprefix $(PARSING_DIR), $(PARSING_SRCS))
EXEC = $(addprefix $(EXEC_DIR), $(EXEC_SRCS))
MAIN = ./main.c
PARSING_OBJS = $(PARSING:.c=.o)
EXEC_OBJS = $(EXEC:.c=.o)
MAIN_OBJS = $(MAIN:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

all : $(NAME)

$(NAME) : $(PARSING_OBJS) $(EXEC_OBJS) $(MAIN_OBJS) $(LIBDIR)/$(LIBFT)
	$(CC) $(CFLAGS) -L libdir -lft -o $(NAME) $(INCLUDE) $(PARSING_OBJS) $(EXEC_OBJS) $(MAIN_OBJS)

$(LIBDIR)/$(LIBFT) :
	make -C $(LIBDIR) all

clean :
	rm -rf $(EXEC_OBJS) $(PARSING_OBJS) $(MAIN_OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all