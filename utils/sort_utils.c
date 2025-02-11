/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:14:20 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/29 13:14:22 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_cheapest(t_stack *s)
{
	if (s == NULL)
		return (NULL);
	while (s != NULL)
	{
		if (s->is_cheapest)
			return (s);
		s = s->next;
	}
	return (NULL);
}

void	get_min_to_top(t_stack **a)
{
	while ((*a)->data != get_min(*a)->data)
	{
		if (get_min(*a)->is_in_first_half)
			ra(a, "ra\n");
		else
			rra(a, "rra\n");
	}
}

void	prepare_for_push(t_stack **s, t_stack *top, char s_name)
{
	while (*s != top)
	{
		if (s_name == 'a')
		{
			if (top->is_in_first_half)
				ra(s, "ra\n");
			else
				rra(s, "rra\n");
		}
		else if (s_name == 'b')
		{
			if (top->is_in_first_half)
				rb(s, "rb\n");
			else
				rrb(s, "rrb\n");
		}
	}
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b, "rr\n");
	set_positions(*a);
	set_positions(*b);
}

void	re_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b, "rrr\n");
	set_positions(*a);
	set_positions(*b);
}
