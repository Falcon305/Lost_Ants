/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:13:58 by hrazani           #+#    #+#             */
/*   Updated: 2020/01/30 16:18:46 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int							correct_path(t_graph *g, int s, int t)
{
	int		tmp;

	tmp = t;
	while (tmp != s)
	{
		adjust_capacity(g, tmp);
		tmp = g->verts[tmp].parent;
	}
	return (1);
}

t_stack						*construct_path(t_graph *g, int s, int t)
{
	int		tmp;
	t_stack	*path;

	path = NULL;
	init_stack(path);
	path = push(path, t);
	tmp = t;
	while (tmp != s)
	{
		if (g->verts[tmp].blocked == 0)
		{
			if (tmp != s && tmp != t)
				g->verts[tmp].blocked = 1;
			path = push(path, g->verts[tmp].parent);
			remove_link(g, tmp, s);
		}
		tmp = g->verts[tmp].parent;
	}
	return (path);
}
