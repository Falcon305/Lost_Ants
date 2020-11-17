/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:19:41 by yoyassin          #+#    #+#             */
/*   Updated: 2019/06/26 15:04:56 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		get_memory(char **str, const char *s, char c)
{
	int index;
	int wsize;
	int nbofwords;

	index = 0;
	nbofwords = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c && s[index] != '\0')
		{
			wsize = 0;
			while (s[index] != c && s[index] != '\0')
			{
				index++;
				wsize++;
			}
			str[nbofwords++] = (char *)malloc(sizeof(**str) * (wsize + 1));
		}
		else
			index++;
	}
}

static void		get_words(char **str, const char *s, char c)
{
	int index;
	int j;
	int k;

	index = 0;
	j = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c && s[index] != '\0')
		{
			k = 0;
			while (s[index] != c && s[index] != '\0')
			{
				str[j][k] = s[index];
				index++;
				k++;
			}
			str[j][k] = '\0';
			j++;
		}
		else
			index++;
	}
	str[j] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		size;
	int		index;

	size = 0;
	index = 0;
	str = NULL;
	if (!s)
		return (NULL);
	while (s[index] != '\0')
	{
		if (s[index] != c && s[index] != '\0')
		{
			size++;
			while (s[index] != c && s[index] != '\0')
				index++;
		}
		else if (s[index] != '\0')
			index++;
	}
	if (!(str = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	get_memory(str, s, c);
	get_words(str, s, c);
	return (str);
}
