/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:11:23 by kilee             #+#    #+#             */
/*   Updated: 2021/02/26 15:01:52 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft.h"
# include "get_next_line.h"
# include "libftprintf.h"
# include "command.h"
# include "utils.h"
# include "tester.h"

# define BUFFER_MAX 4096

int		prompt_show(void);

#endif
