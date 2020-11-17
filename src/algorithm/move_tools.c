/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:31:03 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/14 20:53:46 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void					path_reg(t_path *path)
{
	while (path)
	{
		path->reg = (path->len + 1);
		path = path->next;
	}
}

t_at					*make_at(int nbr)
{
	t_at	*tmp;
	int		i;

	tmp = (t_at *)malloc(sizeof(t_at) * nbr);
	if (!tmp)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < nbr)
	{
		tmp[i].id = 0;
		tmp[i].room = NULL;
		i++;
	}
	return (tmp);
}
