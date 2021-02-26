/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:41:38 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/03 20:37:24 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*target;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	target = new;
	lst = lst->next;
	while (lst)
	{
		if (!(target->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		target = target->next;
		lst = lst->next;
	}
	return (new);
}
