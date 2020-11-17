/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:40:47 by yoyassin          #+#    #+#             */
/*   Updated: 2019/06/26 00:12:02 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	nlen;
	int hlen;

	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (!nlen)
		return ((char *)haystack);
	while (hlen >= nlen)
	{
		if (!ft_strncmp(haystack, needle, nlen))
			return (char *)(haystack);
		haystack++;
		hlen--;
	}
	return (NULL);
}
