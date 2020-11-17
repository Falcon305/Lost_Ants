/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 01:53:56 by yoyassin          #+#    #+#             */
/*   Updated: 2019/10/25 15:06:38 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t nlen;
	size_t hlen;
	size_t i;

	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	i = 0;
	if (!nlen)
		return (char *)(haystack);
	while (hlen >= nlen && i + nlen <= len)
	{
		if (!ft_strncmp(haystack, needle, nlen))
			return (char *)(haystack);
		haystack++;
		hlen--;
		++i;
	}
	return (NULL);
}
