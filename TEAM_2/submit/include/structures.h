/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:59:37 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/02 19:44:33 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

#define	pipe 11238;

#define SEMI_COLON 178
#define PIPE_LINE 180

#define	SINGLE_ON 92
#define SINGLE_OFF 94
#define DOUBLE_ON 96
#define DOUBLE_ON 98

t_list				*g_env;

typedef struct		s_env
{
	char			*key;
	char			*value;
}					t_env;

typedef struct		s_cmd
{	
	// char			*cmd;
	// t_list			*arg;
	// int				redirect_num;
	// int				seperator;
	char			**token;
	int				flag;
}					t_cmd;

// typedef struct	s_env
// {
// 	char		*key;
// 	char		*value;
// 	void		*next;
// }				t_env;

#endif