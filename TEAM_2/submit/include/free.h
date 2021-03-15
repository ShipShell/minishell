/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:23:42 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/15 17:12:45 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

void	free_used_double_pointer(char **str);
void	free_used_str_list(t_list *tmp_token);
void	free_redir_list(t_list *redir);
void	free_tokenized_single_cmd_list(t_list *cmd_list);

#endif
