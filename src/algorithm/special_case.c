/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:56:01 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/09 09:37:54 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int						start_end(t_graph *g)
{
	if (g->adj[g->start][g->end] || g->adj[g->end][g->start])
		return (1);
	return (0);
}

void					print_special(t_graph *g)
{
	int i;

	i = 0;
	while (++i <= g->ants)
	{
		ft_putstr("L");
		ft_putnbr(i);
		ft_putstr("-");
		ft_putstr(g->verts[g->end].name);
		ft_putstr(" ");
	}
	ft_putstr("\n");
}
