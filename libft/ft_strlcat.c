/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 00:31:08 by yoyassin          #+#    #+#             */
/*   Updated: 2019/06/26 00:11:47 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	s_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t d_len;
	size_t s_len;

	s_len = s_strlen(src);
	d_len = s_strlen(dest);
	if (size < d_len + 1)
		return (s_len + size);
	if (size > d_len)
		ft_strncat(dest, src, size - d_len - 1);
	return (d_len + s_len);
}
