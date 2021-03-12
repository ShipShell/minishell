#ifndef PROMPT_H
# define PROMPT_H

int		show_prompt_title(void);
void	exit_with_cntl_d(void);
void	get_prompt_input(char **stdin_buffer);
t_bool	init_prompt(void);
void	loop_prompt(void);

#endif
