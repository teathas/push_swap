/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:24:17 by aberkass          #+#    #+#             */
/*   Updated: 2025/02/02 16:37:00 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	duplicate_check(t_stack *a, int n)
{
	while (a != NULL)
	{
		if (a->data == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	clean_stack(t_stack **s)
{
	t_stack	*curr;
	t_stack	*temp;

	if (*s == NULL)
		return ;
	curr = *s;
	while (curr != NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*s = NULL;
}

void	free_and_exit(t_stack **s, char **args)
{
	clean_stack(s);
	free_splited(args);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
