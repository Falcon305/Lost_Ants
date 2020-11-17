/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:08:31 by yoyassin          #+#    #+#             */
/*   Updated: 2019/06/26 00:11:02 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *mapped;
	t_list *temp;

	if (!(temp = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	mapped = temp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		temp = temp->next;
	}
	return (mapped);
}
