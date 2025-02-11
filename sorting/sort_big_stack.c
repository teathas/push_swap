/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:13:50 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/29 13:13:52 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_b_to_a(t_stack **b, t_stack **a)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*b);
	if (cheapest->is_in_first_half && cheapest->target->is_in_first_half)
		rotate_both(a, b, cheapest);
	else if (cheapest->is_in_first_half == 0
		&& cheapest->target->is_in_first_half == 0)
		re_rotate_both(a, b, cheapest);
	prepare_for_push(b, cheapest, 'b');
	prepare_for_push(a, cheapest->target, 'a');
	pa(a, b, "pa\n");
}

void	sort_big_stack(t_stack **a, t_stack **b)
{
	int	middle_element;

	if (*a == NULL)
		return ;
	middle_element = get_middle_element(*a);
	while (*a != NULL)
	{
		pb(b, a, "pb\n");
		if (*a != NULL && (*b)->data >= middle_element)
			rb(b, "rb\n");
	}
	pa(a, b, "pa\n");
	pa(a, b, "pa\n");
	while (*b != NULL)
	{
		set_b_nodes(*b, *a);
		move_b_to_a(b, a);
	}
	set_positions(*a);
	get_min_to_top(a);
}
