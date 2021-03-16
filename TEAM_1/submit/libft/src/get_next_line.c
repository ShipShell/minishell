/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:10:46 by kilee             #+#    #+#             */
/*   Updated: 2021/03/11 15:38:18 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

void			ft_strfree(char **str)
{
	free(*str);
	*str = NULL;
}

int				ft_cut_to_line(char **room, char **line)
{
	char	*temp;
	char	*n_point;

	if ((n_point = ft_strchr(*room, '\n')))
	{
		*line = ft_strndup(*room, n_point - *room);
		temp = ft_strndup(n_point + 1, ft_strlen(n_point + 1));
		free(*room);
		*room = temp;
		return (1);
	}
	else
	{
		*line = *room;
		*room = NULL;
		return (0);
	}
}

int				ft_output(char **room, char **line, int read_val)
{
	if (read_val < 0)
		return (-1);
	else
		return (ft_cut_to_line(room, line));
}

int				get_next_line(int fd, char **line)
{
	static char	*room[OPEN_MAX + 1];
	char		*buf;
	int			read_val;
	char		*temp;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_val = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[read_val] = '\0';
		if (room[fd] == NULL)
			temp = ft_strndup(buf, read_val);
		else
		{
			temp = ft_strjoin(room[fd], buf);
			free(room[fd]);
		}
		room[fd] = temp;
		if (ft_strchr(room[fd], '\n') || read_val == 0)
			break ;
	}
	ft_strfree(&buf);
	return (ft_output(&room[fd], line, read_val));
}
