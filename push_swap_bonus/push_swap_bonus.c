/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:26:55 by aberkass          #+#    #+#             */
/*   Updated: 2025/02/02 16:43:18 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	checker(t_stack *a)
{
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static int	is_valid_operation(char *operation)
{
	char	*operations[11];
	int		i;

	operations[0] = "pa\n";
	operations[1] = "pb\n";
	operations[2] = "sa\n";
	operations[3] = "sb\n";
	operations[4] = "ss\n";
	operations[5] = "ra\n";
	operations[6] = "rb\n";
	operations[7] = "rr\n";
	operations[8] = "rra\n";
	operations[9] = "rrb\n";
	operations[10] = "rrr\n";
	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(operation, operations[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	operation_not_valid(char **op, t_stack **a, t_stack **b)
{
	clean_stack(a);
	clean_stack(b);
	free(*op);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

int	main(int arc, char **arv)
{
	t_stack		*a;
	t_stack		*b;
	char		*operation;
	char		*joined_args;
	char		**splited_args;

	a = NULL;
	b = NULL;
	if (arc > 1)
	{
		joined_args = join_args(arv, arc);
		splited_args = ft_split(joined_args, ' ');
		free(joined_args);
		fill_stack_a(&a, splited_args);
		free_splited(splited_args);
		operation = get_next_line(0);
		while (operation)
		{
			if (!is_valid_operation(operation))
				operation_not_valid(&operation, &a, &b);
			execute_operation(operation, &a, &b);
			free(operation);
			operation = get_next_line(0);
		}
		checker(a);
		clean_stack(&a);
	}
}
