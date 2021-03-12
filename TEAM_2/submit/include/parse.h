/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:11:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 14:14:13 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "structures.h"
# include "libft.h"

/*
**	parsing 대문함수
*/
t_list	*parse_cmd_line(char *str);

/*
**	syntax error 먼저 잡아내기
*/
int		check_syntax_error(char *str);

/*
**	quoting 판단
*/
void	init_quoting(t_quoting *quoting);
void	change_escape(char c, t_quoting *quoting);
void	change_quotes(char c, t_quoting *quoting);
void	change_quoting(char c, t_quoting *quoting);

/*
**	parsing STEP 1
*/
t_list	*sep_to_single_cmd(char *stdin_buf);

/*
**	parsing STEP 2
*/
t_list	*tokenize(t_list *single_cmd_list);
int		is_tokenizable(char c, t_quoting quoting);
int		get_token_len(char *str);
int		get_token_count(char *str);

/*
**	parsing STEP 3 (replace)
*/
void	replace_token_list(t_list *list_to_replace);
int		check_replace_len(char *str, t_quoting quoting);
char	*replace(char *str, int len, t_quoting *quoting);
char	*join_handled_part(char *result, char *str);
void	handle_redirection(char **token, t_cmd *cmd);
int		check_whether_replace(char c, t_quoting quoting);

#endif
