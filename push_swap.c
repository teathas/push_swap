/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:24:59 by aberkass          #+#    #+#             */
/*   Updated: 2025/02/02 16:37:38 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char *arv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*joined_args;
	char	**splited_args;

	a = NULL;
	b = NULL;
	if (arc > 1)
	{
		joined_args = join_args(arv, arc);
		if (is_only_white_space(joined_args))
		{
			ft_putstr_fd("Error\n", 2);
			free(joined_args);
			return (-1);
		}
		splited_args = ft_split(joined_args, ' ');
		free(joined_args);
		fill_stack_a(&a, splited_args);
		free_splited(splited_args);
		if (!is_sorted(a))
			sort(&a, &b);
		clean_stack(&a);
	}
	return (0);
}
