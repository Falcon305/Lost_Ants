/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:42:29 by yoyassin          #+#    #+#             */
/*   Updated: 2019/06/26 00:11:11 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	if (dest > src)
	{
		d += len;
		s += len;
		while (len--)
		{
			*--d = *--s;
		}
	}
	else
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}
