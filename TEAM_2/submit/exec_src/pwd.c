/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:31:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 14:31:47 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_pwd(void)
{
	char	pwd[MAX_BUFF];

	if (!getcwd(pwd, MAX_BUFF))
		return (-1);
	ft_printf("%s\n", pwd);
	return (1);
}
