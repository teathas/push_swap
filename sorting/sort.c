/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:13:39 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/29 13:13:41 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (a == NULL || *a == NULL)
		return ;
	if (get_stack_len(*a) == 2)
		sa(a, "sa\n");
	else if (get_stack_len(*a) == 3)
		sort_for_three(a);
	else
		sort_big_stack(a, b);
}
