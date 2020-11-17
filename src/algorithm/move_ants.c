/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:12:40 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/08 20:23:38 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void					print_move(int id, char *room)
{
	ft_putstr("L");
	ft_putnbr(id);
	ft_putstr("-");
	ft_putstr(room);
	ft_putstr(" ");
}

void					ant_distrib(t_graph *g, t_group group)
{
	t_path	*tmp;
	int		i;
	int		ants;
	int		holder;

	i = 0;
	ants = g->ants;
	while (ants && i < g->ants)
	{
		holder = group.path->reg;
		tmp = group.path;
		while (tmp)
		{
			if (ants > 0 && tmp->reg <= holder)
			{
				tmp->reg++;
				ants--;
				g->at[i].id = i + 1;
				g->at[i].room = tmp->path;
				i++;
			}
			tmp = tmp->next;
		}
	}
}

int						arrived(t_graph *g)
{
	int		i;

	i = -1;
	while (++i < g->ants)
		if (ft_strcmp(g->verts[g->at[i].room->data].name,
					g->verts[g->end].name) != 0)
			return (1);
	return (0);
}

void					move_ant(t_graph *g, int *x, t_at *at, int current)
{
	int		next;

	next = at[*x].room->next->data;
	print_move(at[*x].id, g->verts[next].name);
	if (ft_strcmp(g->verts[current].name, g->verts[g->start].name) != 0)
		g->verts[current].full = 0;
	if (ft_strcmp(g->verts[next].name, g->verts[g->end].name) != 0)
		g->verts[next].full = 1;
	at[*x].room = at[*x].room->next;
}

void					move_ants(t_graph *g)
{
	t_at	*ants;
	int		ant_number;
	int		current;
	int		next;
	int		x;

	ants = g->at;
	g->ans = 0;
	ant_number = g->ants;
	while (arrived(g))
	{
		x = -1;
		while (++x < ant_number)
			if (ft_strcmp(g->verts[ants[x].room->data].name,
						g->verts[g->end].name) != 0)
			{
				current = ants[x].room->data;
				next = ants[x].room->next->data;
				if (g->verts[next].full == 0)
					move_ant(g, &x, ants, current);
			}
		g->ans++;
		ft_putstr("\n");
	}
}
