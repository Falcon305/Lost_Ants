/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:29:00 by yoyassin          #+#    #+#             */
/*   Updated: 2019/07/14 17:07:36 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	li;

	len = ft_strlen(s);
	i = 0;
	li = len - 1;
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_memset(str, '0', len);
	while (i < len)
	{
		str[i] = s[li];
		i++;
		li--;
	}
	if (s != NULL)
		free(s);
	return (str);
}
