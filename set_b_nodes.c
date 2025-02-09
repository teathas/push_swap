/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_b_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:29:43 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/28 20:29:46 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_stack *s)
{
	int	i;
	int	middle;

	i = 0;
	if (s == NULL)
		return ;
	middle = get_stack_len(s) / 2;
	while (s != NULL)
	{
		s->index = i;
		if (i <= middle)
			s->is_in_first_half = 1;
		else
			s->is_in_first_half = 0;
		s = s->next;
		i++;
	}
}

static void	set_b_targets(t_stack *b, t_stack *a)
{
	t_stack	*current_a;
	t_stack	*target;
	long	closest_index;

	while (b)
	{
		closest_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->data > b->data && current_a->data < closest_index)
			{
				closest_index = current_a->data;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_index == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

static void	set_cost(t_stack *b, t_stack *a)
{
	int	a_size;
	int	b_size;

	a_size = get_stack_len(a);
	b_size = get_stack_len(b);
	while (b != NULL)
	{
		b->cost = b->index;
		if (b->is_in_first_half == 0)
			b->cost = b_size - b->index;
		if (b->target->is_in_first_half)
			b->cost += b->target->index;
		else
			b->cost += a_size - b->target->index;
		b = b->next;
	}
}

static void	set_cheapest(t_stack *s)
{
	long		cheapest_val;
	t_stack		*cheapest;

	if (s == NULL)
		return ;
	cheapest_val = s->cost;
	cheapest = s;
	s = s->next;
	while (s != NULL)
	{
		if (s->cost < cheapest_val)
		{
			cheapest_val = s->cost;
			cheapest = s;
		}
		s = s->next;
	}
	cheapest->is_cheapest = 1;
}

void	set_b_nodes(t_stack *b, t_stack *a)
{
	set_positions(a);
	set_positions(b);
	set_b_targets(b, a);
	set_cost(b, a);
	set_cheapest(b);
}
