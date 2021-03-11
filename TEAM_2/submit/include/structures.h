/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:59:37 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/11 14:02:27 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

#define	pipe 11238;

#define SEMICOLON 178
#define PIPE 180

#define ON 1
#define OFF 2

#define CLOSED 3
#define	SINGLE_OPEN 4
#define DOUBLE_OPEN 5

#define BACKSLASH 92
#define SINGLE_QUOTE 39
#define DOUBLE_QUOTE 34

#define REDIR_IN 182
#define REDIR_OUT 184
#define REDIR_DOUBLE 186

t_list				*g_env;

int					g_exit_code;

typedef int			t_bool;
typedef int			t_quotes;

typedef struct		s_env
{
	char			*key;
	char			*value;
}					t_env;

typedef struct		s_redir
{
	// INDIR : <, OUTDIR : >, DOUBLE : >>
	// 마지막 부분의 redir를 생각하자.
	int				redir_type;
	char			*filename;
	int				fd;
	int				tmp_fd;
}					t_redir;
typedef struct		s_quoting
{
	t_quotes		quotes;
	t_quotes		old_quotes;
	t_bool			escape;
	t_bool			old_escape;
}					t_quoting;

typedef struct		s_cmd
{
	char			**token;
	int				flag;
	int				is_pipe;
	t_list			*redir;
	t_redir			*re_in;
	t_redir			*re_out;
}					t_cmd;

// typedef struct	s_env
// {
// 	char		*key;
// 	char		*value;
// 	void		*next;
// }				t_env;

#endif