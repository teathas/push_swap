/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:25:34 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/16 20:25:37 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_for_three(t_stack **s)
{
	t_stack	*max;

	max = get_max(*s);
	if (max == *s)
		ra(s, "ra\n");
	else if (max == (*s)->next)
		rra(s, "rra\n");
	if ((*s)->data > (*s)->next->data)
		sa(s, "sa\n");
}

void	sort_short(t_stack **a, t_stack **b)
{
	while (get_stack_len(*a) > 3)
	{
		get_min_to_top(a);
		pb(b, a, "pb\n");
	}
	sort_for_three(a);
	while (*b != NULL)
		pa(a, b, "pa\n");
}
