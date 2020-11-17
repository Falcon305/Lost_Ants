/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:15:11 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:07:06 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_fix_sign(char *number)
{
	char	sign;
	int		i;
	t_point	p;

	i = 0;
	p.n1 = ft_strindex(number, '-');
	p.n2 = ft_strindex(number, '+');
	if (p.n1 != -1 || p.n2 != -1)
	{
		i = (p.n1 != -1) ? p.n1 : p.n2;
		sign = (p.n1 != -1) ? '-' : '+';
		if (number[i - 1] == '0')
			number[i] = '0';
	}
	i = 0;
	while (number[i] && number[i] == ' ')
		i++;
	if (sign == '-' || sign == '+')
		number[i] = sign;
	return (number);
}

char		*ft_fix_space(char *number)
{
	int		i;

	i = ft_strindex(number, ' ');
	number[i] = (i >= 1) ? number[i - 1] : number[i];
	number[0] = (i > -1) ? ' ' : number[0];
	return (number);
}
