/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:25:14 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/16 20:25:16 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	append_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (a == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->data = n;
	node->is_cheapest = 0;
	node->is_in_first_half = 0;
	node->cost = 0;
	if (*a == NULL)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last = getlast(*a);
		last->next = node;
		node->prev = last;
	}
}

void	fill_stack_a(t_stack **a, char **args)
{
	int		i;
	long	n;

	i = 0;
	while (args[i] != NULL)
	{
		n = ft_atol(args[i], a, args);
		if (n < INT_MIN || n > INT_MAX)
			free_and_exit(a, args);
		if (duplicate_check(*a, (int)n))
			free_and_exit(a, args);
		append_node(a, (int)n);
		i++;
	}
}
