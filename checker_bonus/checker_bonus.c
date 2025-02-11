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

#include "checker_bonus.h"

static void	checker(t_stack *a)
{
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	if (arc < 2 || (arc == 2 && arv[1][0] == '\0'))
		return (0);
	joined_args = join_args(arv, arc);
	splited_args = ft_split(joined_args, ' ');
	free(joined_args);
	fill_stack_a(&a, splited_args);
	free_splited(splited_args);
	operation = get_next_line(0);
	while (operation)
	{
		execute_operation(operation, &a, &b);
		free(operation);
		operation = get_next_line(0);
	}
	checker(a);
	clean_stack(&a);
}
