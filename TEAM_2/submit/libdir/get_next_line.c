/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:42:39 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/15 10:41:39 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	put_buff(char *box, char **line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (box[i] != '\0' && box[i] != '\n')
		i++;
	*line = (char *)malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		(*line)[j] = box[j];
		j++;
	}
	(*line)[j] = '\0';
}

int		put_line_task(char **box, int read_r, char **ptr, char **line)
{
	char	*temp;

	put_buff(*box, line);
	temp = *box;
	*ptr = ft_strchr(*box, '\n');
	if (*ptr != 0)
		*box = ft_strdup(*ptr + 1);
	free(temp);
	if (read_r == 0 && *ptr == 0)
	{
		*box = 0;
		return (0);
	}
	return (1);
}

void	set_first_box(char **box, int fd)
{
	box[fd] = (char *)malloc(sizeof(char));
	box[fd][0] = '\0';
}

void	read_task(char *buff, int read_r, int fd, char **box)
{
	char	*temp;

	buff[read_r] = '\0';
	temp = box[fd];
	box[fd] = ft_strjoin(box[fd], buff);
	free(temp);
}

int		get_next_line(int fd, char **line)
{
	static char	*fd_box[OPEN_MAX + 1];
	char		*buff;
	int			read_r;
	char		*ptr;

	if (line == 0 || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 ||
		(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == 0)
		return (-1);
	if (fd_box[fd] == 0)
		set_first_box(fd_box, fd);
	while ((read_r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		read_task(buff, read_r, fd, fd_box);
		if (ft_strchr(fd_box[fd], '\n'))
			break ;
	}
	free(buff);
	if (read_r < 0)
		return (-1);
	return (put_line_task(&fd_box[fd], read_r, &ptr, line));
}
