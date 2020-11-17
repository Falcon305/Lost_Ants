/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:11:29 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/14 20:52:54 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void					fill_capacity(t_graph *g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(g->cap = (int **)malloc(sizeof(int *) * g->nbr_verts)))
		exit(EXIT_FAILURE);
	while (i < g->nbr_verts)
	{
		if (!(g->cap[i] = (int *)malloc(sizeof(int) * g->nbr_verts)))
			exit(EXIT_FAILURE);
		j = 0;
		while (j < g->nbr_verts)
		{
			if (g->adj[i][j] == 1)
				g->cap[i][j] = 1;
			else
				g->cap[i][j] = 0;
			j++;
		}
		i++;
	}
}

void					adjust_capacity(t_graph *g, int node)
{
	g->cap[node][g->verts[node].parent] += 1;
	g->cap[g->verts[node].parent][node] -= 1;
}

void					remove_link(t_graph *g, int node, int start)
{
	int con;

	con = g->verts[node].parent;
	if (con != start && node != start)
	{
		if (g->adj[node][con] == 1 && g->adj[con][node] == 1)
		{
			g->adj[node][con] = 2;
			g->adj[con][node] = 2;
		}
	}
}

void					reset_links(t_graph *g)
{
	int i;
	int j;

	i = 0;
	while (i < g->nbr_verts)
	{
		j = 0;
		while (j < g->nbr_verts)
		{
			if (g->adj[i][j] == 2 && g->adj[j][i] == 2)
			{
				g->adj[i][j] = 1;
				g->adj[j][i] = 1;
			}
			j++;
		}
		i++;
	}
}

void					blocked(t_graph *g)
{
	int i;

	i = 0;
	while (i < g->nbr_verts)
	{
		g->verts[i].blocked = 0;
		i++;
	}
}
