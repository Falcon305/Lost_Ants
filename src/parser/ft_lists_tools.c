/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:43:07 by yidabdes          #+#    #+#             */
/*   Updated: 2020/02/14 20:55:02 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		ft_garbadge(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void		ft_init_list(t_data **head)
{
	*head = (t_data *)malloc(sizeof(t_data));
	if (*head == NULL)
		exit(EXIT_FAILURE);
	(*head)->id = -1;
	(*head)->next = NULL;
	(*head)->data = NULL;
}

void		ft_add_list(t_data **head, int id, char *line)
{
	t_data		*new;
	t_data		*tmp;

	tmp = *head;
	if (tmp->id == -1)
	{
		tmp->id = id;
		tmp->data = strdup(line);
		tmp->next = NULL;
	}
	else
	{
		if (!(new = (t_data *)malloc(sizeof(t_data))))
			exit(EXIT_FAILURE);
		new->id = id;
		new->data = strdup(line);
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		ft_print_list(t_data *head)
{
	t_data *current;

	current = head;
	while (current)
	{
		ft_printf("%s\n", current->data);
		current = current->next;
	}
	ft_putstr("\n");
}

void		ft_free_list(t_data *head)
{
	t_data *tmp;

	tmp = NULL;
	while (head != NULL)
	{
		tmp = head;
		if (tmp->data != NULL)
			free(tmp->data);
		(head) = (head)->next;
		free(tmp);
	}
	free(head);
	head = NULL;
}
