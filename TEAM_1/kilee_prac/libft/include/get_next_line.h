/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:49:10 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/11/25 13:42:07 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*
** Define BUFFER_SIZE when doesn't define during compile
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

/*
** Define OPEN_MAX when can't include <limits.h>
*/
# ifndef OPEN_MAX
#  define OPEN_MAX 12800
# endif

int			get_next_line(int fd, char **line);

#endif
