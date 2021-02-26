/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:40:27 by hson              #+#    #+#             */
/*   Updated: 2021/02/26 10:47:14 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1000

int	is_newline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_make_line(char **save, char **line, int cut_idx)
{
	int		len;
	char	*tmp;

	(*save)[cut_idx] = '\0';
	*line = ft_strdup(*save);
	if ((len = ft_strlen(*save + cut_idx + 1)) > 0)
	{
		tmp = ft_strdup(*save + cut_idx + 1);
		free(*save);
		*save = tmp;
		return (1);
	}
	else
	{
		free(*save);
		*save = 0;
		return (1);
	}
}

int	ft_all_return(char **save, char **line, int len)
{
	int cut_idx;

	if (len < 0)
		return (-1);
	if (*save && (cut_idx = is_newline(*save)) >= 0)
		return (ft_make_line(save, line, cut_idx));
	if (*save)
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			len;
	int			cut_idx;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[len] = '\0';
		tmp = save[fd];
		save[fd] = ft_strjoin(save[fd], buf);
		free(tmp);
		if ((cut_idx = is_newline(save[fd])) >= 0)
			return (ft_make_line(&save[fd], line, cut_idx));
	}
	return (ft_all_return(&save[fd], line, len));
}
