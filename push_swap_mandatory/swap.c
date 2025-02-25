/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:26:12 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/16 20:26:15 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **s)
{
	t_stack	*tmp;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	tmp = (*s)->next;
	(*s)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *s;
	tmp->prev = NULL;
	tmp->next = *s;
	(*s)->prev = tmp;
	*s = tmp;
}

void	sa(t_stack **a, char *op)
{
	swap(a);
	ft_putstr_fd(op, 1);
}

void	sb(t_stack **b, char *op)
{
	swap(b);
	ft_putstr_fd(op, 1);
}

void	ss(t_stack **a, t_stack **b, char *op)
{
	swap(a);
	swap(b);
	ft_putstr_fd(op, 1);
}
