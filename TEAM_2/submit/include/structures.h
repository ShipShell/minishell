/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev_mj <dev_mj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:59:37 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/06 17:19:44 by dev_mj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

#define	MAX_BUFF 1000

#define	pipe 11238;

#define SEMICOLON 178
#define PIPELINE 180

#define ON 1
#define OFF 2

#define CLOSED 3
#define	SINGLE_OPEN 4
#define DOUBLE_OPEN 5

#define BACKSLASH 92
#define SINGLE_QUOTE 39
#define DOUBLE_QUOTE 34

t_list				*g_env;
int					g_exit_code;

typedef int			t_bool;
typedef int			t_quotes;

typedef int			t_bool;
typedef int			t_quotes;

typedef struct		s_env
{
	char			*key;
	char			*value;
}					t_env;

typedef struct		s_quoting
{
	t_quotes		quotes;
	t_bool			escape;
	t_bool			old_escape;
}					t_quoting;

typedef struct		s_cmd
{
	char			**token;
	int				flag;
	int				is_pipe;
}					t_cmd;

#endif