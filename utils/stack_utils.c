/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:25:43 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/16 20:25:46 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_stack_len(t_stack *a)
{
	int	len;

	len = 0;
	while (a != NULL)
	{
		a = a->next;
		len++;
	}
	return (len);
}

t_stack	*getlast(t_stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next != NULL)
		a = a->next;
	return (a);
}

int	is_sorted(t_stack *s)
{
	if (s == NULL)
		return (1);
	while (s->next != NULL)
	{
		if (s->data > s->next->data)
			return (0);
		s = s->next;
	}
	return (1);
}

t_stack	*get_max(t_stack *s)
{
	t_stack	*max;

	max = s;
	while (s != NULL)
	{
		if (s->data > max->data)
			max = s;
		s = s->next;
	}
	return (max);
}

t_stack	*get_min(t_stack *s)
{
	long	min;
	t_stack	*min_node;

	min = s->data;
	min_node = s;
	s = s->next;
	while (s != NULL)
	{
		if (s->data < min)
		{
			min = s->data;
			min_node = s;
		}
		s = s->next;
	}
	return (min_node);
}
