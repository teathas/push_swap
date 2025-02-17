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
	if (ft_strcmp(operation, "sa") == 0)
		sa(a, NULL);
	else if (ft_strcmp(operation, "sb") == 0)
		sb(b, NULL);
	else if (ft_strcmp(operation, "ss") == 0)
		ss(a, b, NULL);
}

static void	ex_push(char *operation, t_stack **a, t_stack **b)
{
	if (ft_strcmp(operation, "pa") == 0)
		pa(a, b, NULL);
	else if (ft_strcmp(operation, "pb") == 0)
		pb(b, a, NULL);
}

static void	ex_rotate(char *operation, t_stack **a, t_stack **b)
{
	if (ft_strcmp(operation, "ra") == 0)
		ra(a, NULL);
	else if (ft_strcmp(operation, "rb") == 0)
		rb(b, NULL);
	else if (ft_strcmp(operation, "rr") == 0)
		rr(a, b, NULL);
}

static void	ex_re_rotate(char *operation, t_stack **a, t_stack **b)
{
	if (ft_strcmp(operation, "rra") == 0)
		rra(a, NULL);
	else if (ft_strcmp(operation, "rrb") == 0)
		rrb(b, NULL);
	else if (ft_strcmp(operation, "rrr") == 0)
		rrr(a, b, NULL);
}

void	execute_operation(char *op, t_stack **a, t_stack **b)
{
		ex_swap(op, a, b);
		ex_push(op, a, b);
		ex_rotate(op, a, b);
		ex_re_rotate(op, a, b);
}
