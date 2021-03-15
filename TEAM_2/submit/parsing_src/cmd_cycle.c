#include "minishell.h"

char	*join_and_abandon(char *str1, char *str2)
{
	char	*garbage;

	if (str1 == 0 || str2 == 0)
		return (0);
	garbage = str1;
	str1 = ft_strjoin(str1, str2);
	free(garbage);
	free(str2);
	return (str1);
}

char	*attach_stdin_buf(char *stdin_buf)
{
	int		len;
	char	*tmp;

	len = ft_strlen(stdin_buf);
	if (len)
	{
		if (tmp == 0)
			tmp = ft_strdup(stdin_buf);
		else
			tmp = join_and_abandon(tmp, stdin_buf);
	}
	if (len == 0 && tmp == 0)
		exit_by_cntl_d();
	ft_putstr_fd("  \b\b  \b\b", 1);
	return (tmp);
}

int		wait_cmd(void)
{
	char	*stdin_buf;
	t_list	*tokenized_single_cmd_list;
	char	*tmp;
	int		len;

	tmp = 0;
	show_prompt();
	while (get_next_line(0, &stdin_buf) == 0)
		tmp = attach_stdin_buf(stdin_buf);
	if (tmp != 0)
		stdin_buf = join_and_abandon(tmp, stdin_buf);
	tokenized_single_cmd_list = parse_cmd_line(stdin_buf);
	if (tokenized_single_cmd_list != NULL)
	{
		cycle_list(tokenized_single_cmd_list);
		free_tokenized_single_cmd_list(tokenized_single_cmd_list);
	}
	free(stdin_buf);
	return (0);
}