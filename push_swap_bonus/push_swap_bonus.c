/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:26:55 by aberkass          #+#    #+#             */
/*   Updated: 2025/02/17 16:36:50 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	checker(t_stack **a, t_stack **b)
{
	if (is_sorted(*a) && !get_stack_len(*b))
		write(1, "OK\n", 3);
	else
	{
		write(1, "KO\n", 3);
		clean_stack(b);
	}
	clean_stack(a);
}

int	main(int arc, char **arv)
{
	t_stack	*a;
	t_stack	*b;
	char	*operations;
	char	*joined_args;
	char	**splited_args;

	a = NULL;
	b = NULL;
	if (arc == 1)
		return (1);
	joined_args = join_args(arv, arc);
	if (joined_args == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	splited_args = ft_split(joined_args, ' ');
	free(joined_args);
	fill_stack_a(&a, splited_args);
	free_splited(splited_args);
	operations = read_operations(&a);
	if (operations != NULL)
		execute_operations(&a, &b, operations);
	checker(&a, &b);
	return (0);
}
