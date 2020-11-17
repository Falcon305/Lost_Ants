/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:08:32 by yoyassin          #+#    #+#             */
/*   Updated: 2019/07/04 19:18:35 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = malloc(sizeof(char) * size + 1);
	if (str == 0)
		return (NULL);
	else
		ft_bzero(str, size + 1);
	str[size] = '\0';
	return (str);
}
