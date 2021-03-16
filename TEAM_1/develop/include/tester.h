/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:07:12 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 13:07:13 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <stdio.h>
# include "parser.h"

void	test_init_g_env(t_env *envs);
void	test_make_cmd_str_to_tokens(void);
void	test_change_quoting(void);
void	test_parse_cmd_from_input(void);
void	test_check_cmd_list_redirection(t_cmd *cmd);

#endif
