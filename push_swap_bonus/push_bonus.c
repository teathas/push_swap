/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:25:52 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/16 20:25:55 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*topush;

	if (*src == NULL)
		return ;
	topush = *src;
	*src = (*src)->next;
	topush->prev = NULL;
	if (*dst == NULL)
	{
		topush->next = NULL;
		*dst = topush;
	}
	else
	{
		topush->next = *dst;
		topush->next->prev = topush;
		*dst = topush;
	}
}

void	pa(t_stack **a, t_stack **b, char *op)
{
	push(a, b);
	ft_putstr_fd(op, 1);
}

void	pb(t_stack **b, t_stack **a, char *op)
{
	push(b, a);
	ft_putstr_fd(op, 1);
}
