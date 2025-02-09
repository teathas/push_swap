/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:25:59 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/16 20:26:01 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	last = getlast(*s);
	tmp = *s;
	*s = (*s)->next;
	(*s)->prev = NULL;
	tmp->next = NULL;
	last->next = tmp;
	tmp->prev = last;
}

void	ra(t_stack **a, char *op)
{
	rotate(a);
	ft_putstr_fd(op, 1);
}

void	rb(t_stack **b, char *op)
{
	rotate(b);
	ft_putstr_fd(op, 1);
}

void	rr(t_stack **a, t_stack **b, char *op)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd(op, 1);
}
