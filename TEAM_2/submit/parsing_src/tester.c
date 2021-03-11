#include "minishell.h"

static char		*tester(int i)
{
	if (i == 1)
		return ("ON");
	else if (i == 2)
		return ("OFF");
	else if (i == 3)
		return ("CLOSED");
	else if (i == 4)
		return ("SINGLE_OPEN");
	else if (i == 5)
		return ("DOUBLE_OPEN");
	else if (i == 182)
		return ("REDIR_IN");
	else if (i == 184)
		return ("REDIR_OUT");
	else if (i == 186)
		return ("REDIR_DOUBLE");
	else
		return (NULL);
}

void	test_change_quoting(t_quoting quoting)
{
	printf("quotes : %s\nescape : %s\nold_escape : %s\n",
		tester(quoting.quotes), tester(quoting.escape), tester(quoting.old_escape));
}

void	test_save_redir_list(t_list *redir_list)
{
	while (redir_list)
	{
		printf("redir_type : %s\n", tester(((t_redir *)(redir_list->content))->redir_type));
		printf("filename : %s\n", ((t_redir *)(redir_list->content))->filename);
		redir_list = redir_list->next;
	}
}

void	test_save_tmp_token(t_list *tmp)
{
	while (tmp)
	{
		ft_printf("token : %s\n", (char *)(tmp->content));
		tmp = tmp->next;
	}
}

void	test_list_to_token(char **token)
{
	int		i;

	i = 0;
	while (token[i])
	{
		printf("token[%d] : %s\n", i, token[i]);
		++i;
	}
}