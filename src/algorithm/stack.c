/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:27:41 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/14 20:54:30 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void					init_stack(t_stack *head)
{
	head = NULL;
}

t_stack					*push(t_stack *head, int data)
{
	t_stack	*tmp;

	tmp = (t_stack*)malloc(sizeof(t_stack));
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	tmp->data = data;
	tmp->next = head;
	head = tmp;
	return (head);
}

t_stack					*pop(t_stack *head, int *element)
{
	t_stack	*tmp;

	tmp = head;
	*element = head->data;
	head = head->next;
	free(tmp);
	return (head);
}

int						empty(t_stack *head)
{
	return (head == NULL ? 1 : 0);
}

int						stack_len(t_stack *path)
{
	int		len;

	len = 0;
	while (path)
	{
		++len;
		path = path->next;
	}
	return (len);
}
