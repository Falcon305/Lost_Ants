/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:48:22 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:06:53 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	garbage(char *str1, char *str2)
{
	if (str1 != NULL)
		free(str1);
	if (str2 != NULL)
		free(str2);
}

void		ini_mult(t_mult *m, int *s, int *carry, char c)
{
	if (c == 'm')
	{
		m->m = 0;
		m->i.n1 = 0;
		m->i.n2 = 0;
		m->len.n1 = 0;
		m->len.n2 = 0;
		m->carry = 0;
		m->nbr.n1 = 0;
		m->nbr.n2 = 0;
	}
	else
	{
		*carry = 0;
		*s = 0;
	}
}

char		*add(char *nbr1, char *nbr2)
{
	t_point	l;
	char	*out;
	int		carry;
	int		s;
	int		i;

	ini_mult(NULL, &s, &carry, 'a');
	ft_swap_rev(&nbr1, &nbr2, &l);
	out = ft_strnew(l.n2 + 2);
	i = 0;
	while (i < l.n2)
	{
		if (i < l.n1)
			s = I(nbr1[i]) + I(nbr2[i]) + carry;
		else if (i < l.n2)
			s = I(nbr2[i]) + carry;
		out[i] = C(s);
		carry = s / 10;
		i++;
	}
	if (carry)
		out[i] = C(carry);
	out = ft_strrev(out);
	garbage(nbr1, nbr2);
	return (out);
}

void		multiply_helper(char **nbr1, char **nbr2, char **out, t_mult *m)
{
	ini_mult(m, 0, 0, 'm');
	ft_swap(nbr1, nbr2, &m->len);
	*out = ft_strnew(m->len.n1 + m->len.n2);
	ft_memset(*out, '0', m->len.n1 + m->len.n2);
	m->i.n1 = m->len.n1 - 1;
}

char		*multiply(char *nbr1, char *nbr2)
{
	char	*out;
	t_mult	m;

	multiply_helper(&nbr1, &nbr2, &out, &m);
	while (m.i.n1 >= 0)
	{
		m.i.n2 = m.len.n2 - 1;
		while (m.i.n2 >= 0)
		{
			m.nbr.n1 = I(nbr1[m.i.n1]);
			m.nbr.n2 = I(nbr2[m.i.n2]);
			m.m = m.nbr.n1 * m.nbr.n2 + I(out[m.i.n2 + m.i.n1 + 1]) + m.carry;
			m.carry = m.m / 10;
			out[m.i.n2 + m.i.n1 + 1] = C(m.m);
			m.i.n2--;
			if (m.i.n2 == -1)
			{
				out[m.i.n2 + m.i.n1 + 1] = C(m.carry);
				m.carry = 0;
			}
		}
		m.i.n1--;
	}
	garbage(nbr1, nbr2);
	return (out);
}
