/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 23:42:06 by yoyassin          #+#    #+#             */
/*   Updated: 2019/06/26 00:11:52 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char const *src, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (dest[len])
		len++;
	while (src[i] && n > 0)
	{
		dest[len + i] = src[i];
		i++;
		n--;
	}
	dest[len + i] = '\0';
	return (dest);
}
