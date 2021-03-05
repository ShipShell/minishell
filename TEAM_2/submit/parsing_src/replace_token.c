/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:50:11 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/05 17:00:10 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *replace_wave(void)
{
	t_list		*env_list;

	env_list = g_env;
	while(ft_strncmp(((t_env *)(env_list->content))->key, "HOME", 4))
		env_list = env_list->next;
	return (((t_env *)(env_list->content))->value);
}

static char *check_and_replace(char *str)
{
	int			len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\t' && str[len] != ' ')
		len++;
	if (len == 1 && str[0] == '~')
		return (replace_wave());
	else if (len == 1 && str[0] == '$')
		return ("$");
	else if (len != 1 && str[0] == '$')
		return (replace_dollar(ft_strndup(str, len)));
	else
		return (NULL);
}

// static char	*handle_special_character(char *str)
static void	handle_special_character(char *str)
{
	int			i;
	char		*replaced;
	char		*result;
	t_quoting	quoting;

	i = 0;
	result = NULL;
	init_quoting(&quoting);
	while (str[i])
	{	
		change_quoting(str[i], &quoting);
		if ((str[i] == '$' || str[i] == '~') && quoting.quotes != SINGLE_OPEN && quoting.old_escape == OFF)
		{
			replaced = check_and_replace(str + i);
			
		}
			// replaced_part = check_and_replace(str + i);
			// ft_strjoin(, replaced_part);
		++i;
	}
}

void		replace_token(char **token)
{
	int 		i;

	i = 0;
	if (token[i] == NULL)
		return ;
	while (token[i])
	{
		// token[i] = 
		handle_special_character(token[i]);
		// trim_quotes(token[i]);
		++i;
	}
}