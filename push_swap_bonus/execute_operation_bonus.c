/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:27:03 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/28 20:27:05 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ex_swap(char *operation, t_stack **a, t_stack **b)
{
	if (ft_strcmp(operation, "sa\n") == 0)
		sa(a, NULL);
	else if (ft_strcmp(operation, "sb\n") == 0)
		sb(b, NULL);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(a, b, NULL);
}

static void	ex_push(char *operation, t_stack **a, t_stack **b)
{
	if (ft_strcmp(operation, "pa\n") == 0)
		pa(a, b, NULL);
	else if (ft_strcmp(operation, "pb\n") == 0)
		pb(b, a, NULL);
}

static void	ex_rotate(char *operation, t_stack **a, t_stack **b)
{
	if (ft_strcmp(operation, "ra\n") == 0)
		ra(a, NULL);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rb(b, NULL);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(a, b, NULL);
}

static void	ex_re_rotate(char *operation, t_stack **a, t_stack **b)
{
	if (ft_strcmp(operation, "rra\n") == 0)
		rra(a, NULL);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		rrb(b, NULL);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(a, b, NULL);
}

void	execute_operation(char *op, t_stack **a, t_stack **b)
{
	ex_swap(op, a, b);
	ex_push(op, a, b);
	ex_rotate(op, a, b);
	ex_re_rotate(op, a, b);
}
