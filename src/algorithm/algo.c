/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:43:01 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/17 02:11:16 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_group					best_group(t_group *group)
{
	int		curr;
	t_group	best;

	curr = 1000; 
	best = (*group);
	while (group)
	{
		if (curr > group->score)
		{
			curr = group->score;
			best = (*group);
		}
		group = group->next;
	}
	return (best);
}

t_group					*algo(t_graph *g, int s, int t)
{
	t_algo	vars;

	vars.max_group = -1;
	vars.pt = NULL;
	vars.path = NULL;
	vars.group = NULL;
	init_g(&vars.group);
	init_stack(vars.path);
	while (bfs_corr(g, s, t) && ++vars.max_group < 20)
	{
		blocked(g);
		init_p(&vars.pt);
		while ((vars.path = bfs_path(g, s, t)))
			add_p(&vars.pt, vars.path);
		add_g(&vars.group, vars.pt, g);
		reset_links(g);
	}
	return (vars.group);
}

void					output(t_graph *g, int s, int t, t_data *data)
{
	t_group	*group;
	t_group	best;

	group = algo(g, s, t);
	if (group->score == -1)
	{
		ft_putstr("ERROR : No Path Has Been Found\n");
		exit(EXIT_FAILURE);
	}
	ft_print_list(data);
	best = best_group(group);
	path_reg(best.path);
	g->at = make_at(g->ants);
	ant_distrib(g, best);
	move_ants(g);
	free_g(group);
	free_links(g);
	free(g->at);
}
