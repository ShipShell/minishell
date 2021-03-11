#include "minishell.h"

char	 *join_handled_part(char *result, char *str)
{
	char		*tmp;

	if (result == NULL)
		result = ft_strdup(str);
	else
	{
		tmp = result;
		result = ft_strjoin(tmp, str);
		free (tmp);
	}
	return (result);
}