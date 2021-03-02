/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:50:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/31 16:33:18 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*join_buf(char **store, char *buf, int readsize)
{
	char		*result;

	buf[readsize] = '\0';
	if (*store == 0)
		result = ft_strndup(buf, readsize);
	else
		result = ft_strjoin(*store, buf);
	return (result);
}

int				reset_and_return(char **store, char **line, int rs)
{
	char		*reset;
	char		*pin;

	if (rs < 0)
		return (-1);
	else
	{
		if ((pin = ft_strchr(*store, '\n')))
		{
			*line = ft_strndup(*store, pin - *store);
			reset = ft_strndup(pin + 1, ft_strlen(pin + 1));
			free(*store);
			*store = reset;
			return (1);
		}
		else
		{
			*line = *store;
			*store = NULL;
			return (0);
		}
	}
}

int				get_next_line(int fd, char **line)
{
	static char	*store[OPEN_MAX + 1];
	char		*buf;
	int			readsize;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((readsize = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		tmp = join_buf(&store[fd], buf, readsize);
		store[fd] = tmp;
		if (ft_strchr(store[fd], '\n') || readsize == 0)
			break ;
	}
	free(buf);
	buf = 0;
	return (reset_and_return(&store[fd], line, readsize));
}
