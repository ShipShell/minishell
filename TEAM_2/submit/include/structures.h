/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:59:37 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/02/28 18:34:08 by hyeonkim         ###   ########.fr       */
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
#define MAX_BUFF 500

t_list				*g_env;

typedef struct		s_env
{
	char			*key;
	char			*value;
}					t_env;

typedef struct		s_cmd
{
	char **token;
	int flag;
}					t_cmd;

#endif