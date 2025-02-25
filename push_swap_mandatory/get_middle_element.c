/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_middle_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:22:52 by aberkass          #+#    #+#             */
/*   Updated: 2025/02/11 18:22:56 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_stack(t_stack *a)
{
	t_stack	*curr;
	int		*ret;
	int		i;

	ret = malloc(get_stack_len(a) * sizeof(int));
	if (ret == NULL)
		return (NULL);
	i = 0;
	curr = a;
	while (curr != NULL)
	{
		ret[i] = curr->data;
		i++;
		curr = curr->next;
	}
	return (ret);
}

static void	insertion_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < size)
	{
		tmp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
		i++;
	}
}

int	get_middle_element(t_stack *a)
{
	int	*array;
	int	size;
	int	middle_element;

	array = copy_stack(a);
	size = get_stack_len(a);
	insertion_sort(array, size);
	middle_element = array[size / 2];
	free(array);
	return (middle_element);
}
