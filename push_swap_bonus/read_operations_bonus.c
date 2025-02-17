/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 07:53:10 by aberkass          #+#    #+#             */
/*   Updated: 2025/02/17 16:44:05 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_valid_operation(char *op)
{
	int				i;
	char			*operations[12];

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
	operations[11] = NULL;
	i = 0;
	while (operations[i])
	{
		if (ft_strcmp(op, operations[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	execute_operations(t_stack **a, t_stack **b, char *op)
{
	int				i;
	char			**operations;

	operations = ft_split(op, '\n');
	free(op);
	i = 0;
	while (operations[i])
	{
		execute_operation(operations[i], a, b);
		i++;
	}
	free_splited(operations);
}

char	*read_operations(t_stack **a)
{
	char	*operations;
	char	*op;

	operations = NULL;
	op = get_next_line(0);
	while (op)
	{
		if (is_valid_operation(op) == 0)
		{
			free(op);
			if (operations)
				free(operations);
			clean_stack(a);
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		operations = ft_strjoin_gnl(operations, op);
		free(op);
		op = get_next_line(0);
	}
	return (operations);
}
