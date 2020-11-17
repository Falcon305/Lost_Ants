/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:31:41 by hrazani           #+#    #+#             */
/*   Updated: 2020/01/30 17:05:59 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

long int				ciel(float f)
{
	long int	n;

	n = (long int)f;
	if (f == (float)n)
		return (n);
	return (n + 1);
}

int						calc_score(t_graph *g, int paths, int nodes)
{
	int			score;

	score = ciel(nodes + g->ants) / (float)paths;
	return (score);
}
