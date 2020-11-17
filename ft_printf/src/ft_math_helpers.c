/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 22:37:19 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:06:50 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_rm_zeros(char *res)
{
	char	*des;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(res);
	while (res[i] == '0')
		i++;
	des = ft_strnew(len - i);
	while (i < len)
	{
		des[j] = res[i];
		i++;
		j++;
	}
	free(res);
	return (des);
}

char		*ft_power(char *nbr, int pow)
{
	char	*res;
	char	*tmp;

	res = strdup("1");
	while (pow-- > 0)
	{
		tmp = ft_strdup(res);
		if (res != NULL)
			free(res);
		res = multiply(tmp, ft_strdup(nbr));
	}
	return (res);
}

int			ft_swap_rev(char **str1, char **str2, t_point *l)
{
	char	*tmp;

	l->n1 = ft_strlen(*str1);
	l->n2 = ft_strlen(*str2);
	if (l->n1 <= l->n2)
	{
		*str2 = ft_strrev(*str2);
		*str1 = ft_strrev(*str1);
		return (l->n2);
	}
	else if (l->n1 > l->n2)
	{
		tmp = *str2;
		*str2 = ft_strrev(*str1);
		*str1 = ft_strrev(tmp);
		l->n1 = ft_strlen(*str1);
		l->n2 = ft_strlen(*str2);
		return (l->n2);
	}
	return (l->n1);
}

int			ft_swap(char **str1, char **str2, t_point *l)
{
	char	*tmp;

	l->n1 = ft_strlen(*str1);
	l->n2 = ft_strlen(*str2);
	if (l->n1 <= l->n2)
	{
		*str2 = *str2;
		*str1 = *str1;
		return (l->n2);
	}
	else if (l->n1 > l->n2)
	{
		tmp = *str2;
		*str2 = *str1;
		*str1 = tmp;
		l->n1 = ft_strlen(*str1);
		l->n2 = ft_strlen(*str2);
		return (l->n2);
	}
	return (l->n1);
}
