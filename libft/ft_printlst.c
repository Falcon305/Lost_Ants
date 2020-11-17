/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:23:54 by yoyassin          #+#    #+#             */
/*   Updated: 2019/06/26 00:11:12 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list *lst)
{
	while (lst)
	{
		ft_putstr((char *)lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
}
