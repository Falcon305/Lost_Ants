/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:16:34 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/09 16:14:52 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static int			corr_help(t_graph *g, int i, int curr)
{
	if (g->adj[curr][i] == 1 && g->verts[i].visited == 0 && g->cap[curr][i] > 0
			&& (g->verts[i].blocked == g->verts[curr].blocked ||
			(g->verts[curr].blocked == 0
			&& g->verts[i].blocked == 1) ||
			(g->verts[curr].blocked == 1 &&
			g->verts[g->verts[curr].parent].blocked == 1
			&& g->verts[i].blocked == 0)))
	{
		g->verts[i].parent = curr;
		g->verts[i].visited = 1;
		return (1);
	}
	return (0);
}

static int			path_help(t_graph *g, int i, int curr)
{
	if (g->adj[curr][i] == 1 && g->verts[i].visited == 0 &&
		g->cap[curr][i] == 0 && g->verts[i].blocked == 0)
	{
		g->verts[i].parent = curr;
		g->verts[i].visited = 1;
		return (1);
	}
	return (0);
}

void				corr_end(t_graph *g, t_bfs vars)
{
	if (!vars.list->next && g->verts[vars.curr].blocked == 1
		&& end_road(g, vars.curr)
		&& g->verts[g->verts[vars.curr].parent].blocked == 0)
		g->verts[vars.curr].visited = 0;
}

int					bfs_corr(t_graph *g, int s, int t)
{
	t_bfs	vars;

	vars.q = queue_create();
	visited(g);
	enq(vars.q, s);
	g->verts[s].visited = 1;
	while (!queue_empty(vars.q))
	{
		vars.curr = deq(vars.q);
		vars.list = g->verts[vars.curr].list;
		while (vars.list)
		{
			vars.near = vars.list->value;
			if (corr_help(g, vars.near, vars.curr))
			{
				if (vars.near == t && queue_destroy(vars.q))
					return (correct_path(g, s, t));
				enq(vars.q, vars.near);
			}
			corr_end(g, vars);
			vars.list = vars.list->next;
		}
	}
	queue_destroy(vars.q);
	return (0);
}

t_stack				*bfs_path(t_graph *g, int s, int t)
{
	t_bfs	vars;

	vars.q = queue_create();
	visited(g);
	enq(vars.q, s);
	g->verts[s].visited = 1;
	while (!queue_empty(vars.q))
	{
		vars.curr = deq(vars.q);
		vars.list = g->verts[vars.curr].list;
		while (vars.list)
		{
			vars.near = vars.list->value;
			if (path_help(g, vars.near, vars.curr))
			{
				if (vars.near == t && queue_destroy(vars.q))
					return (construct_path(g, s, t));
				enq(vars.q, vars.near);
			}
			vars.list = vars.list->next;
		}
	}
	queue_destroy(vars.q);
	return (NULL);
}
