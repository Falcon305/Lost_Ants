/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 21:48:45 by yoyassin          #+#    #+#             */
/*   Updated: 2019/06/26 00:12:04 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	s_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		lenght;
	int		end;

	if (s)
	{
		start = 0;
		end = ft_strlen(s);
		while (s_space(s[start]))
			start++;
		end--;
		while (s_space(s[end]))
			end--;
		lenght = end - start + 1;
		if (lenght <= 0)
			lenght = 1;
		if (!(str = ft_strsub(s, start, lenght)))
			return (NULL);
		if (lenght == 1)
			str[0] = '\0';
		return (str);
	}
	return (0);
}
