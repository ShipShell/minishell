/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:25:40 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/06 19:19:20 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp_result;

	if (lst == 0)
		return (0);
	if ((temp_result = ft_lstnew(f(lst->content))) == 0)
	{
		ft_lstclear(&temp_result, del);
		return (0);
	}
	result = temp_result;
	lst = lst->next;
	while (lst)
	{
		if ((temp_result->next = ft_lstnew(f(lst->content))) == 0)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		temp_result = temp_result->next;
		lst = lst->next;
	}
	return (result);
}
