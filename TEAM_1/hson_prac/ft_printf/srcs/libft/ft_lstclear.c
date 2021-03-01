/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 02:28:52 by hson              #+#    #+#             */
/*   Updated: 2020/10/14 19:46:16 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *c;

	if (!lst || !del)
		return ;
	c = *lst;
	while (c != NULL)
	{
		ft_lstdelone(c, del);
		c = c->next;
	}
	*lst = NULL;
}
