/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:54:23 by yidabdes          #+#    #+#             */
/*   Updated: 2020/01/30 19:19:17 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	ft_free_line(char *line)
{
	if (line != NULL)
		free(line);
	line = NULL;
}

int		ft_read_data(t_data **head, int *nbr_links, t_graph *g)
{
	int		ret;
	int		i;
	char	*line;

	ret = NO_MATCH;
	ft_init_list(head);
	i = 0;
	while (get_next_line(0, &line) == 1)
	{
		ret = ft_checker(head, line, i, g);
		ft_free_line(line);
		if (ret == ROOM_ERROR || ret == NO_MATCH || ret == LINK_ERROR ||
			ret == ANTS_ERROR)
			return (ret);
		i++;
	}
	ft_free_line(line);
	if (i == 0)
		return (NO_MATCH);
	if ((ret = ft_check_start_end(head, nbr_links)) != 1)
		return (ret);
	return (1);
}
