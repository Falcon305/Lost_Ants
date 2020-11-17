/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:44:17 by yidabdes          #+#    #+#             */
/*   Updated: 2020/01/30 19:15:57 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int				ft_whitespace(char c)
{
	if (c == '\n' || c == '\t' || c == '\v')
		return (1);
	else if (c == ' ' || c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

long int				ft_atoi(const char *str)
{
	long int	i;
	int			sign;
	long int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_whitespace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	if (sign == 1 && str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + (str[i] - 48);
		i++;
	}
	if (res < -2147483648)
		return (sign == 1 ? -1 : 0);
	return (res * sign);
}
