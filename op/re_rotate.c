/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:26:05 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/16 20:26:07 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	re_rotate(t_stack **s)
{
	t_stack	*last;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	last = getlast(*s);
	last->prev->next = NULL;
	last->next = *s;
	(*s)->prev = last;
	*s = last;
}

void	rra(t_stack **a, char *op)
{
	re_rotate(a);
	ft_putstr_fd(op, 1);
}

void	rrb(t_stack **b, char *op)
{
	re_rotate(b);
	ft_putstr_fd(op, 1);
}

void	rrr(t_stack **a, t_stack **b, char *op)
{
	re_rotate(a);
	re_rotate(b);
	ft_putstr_fd(op, 1);
}
