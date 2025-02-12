/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:37:45 by aberkass          #+#    #+#             */
/*   Updated: 2025/02/02 16:38:13 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char	*str, t_stack **a, char **args)
{
	int				sign;
	int				i;
	long			res;

	sign = 1;
	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		free_and_exit(a, args);
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
		free_and_exit(a, args);
	return (res * sign);
}

void	free_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

char	*join_args(char **arv, int arc)
{
	char	*tmp;
	char	*joined_args;
	int		i;

	if (is_only_white_space(arv[1]))
		return (NULL);
	joined_args = ft_strjoin("", arv[1]);
	i = 2;
	while (i < arc)
	{
		if (arv[i][0] == '\0' || is_only_white_space(arv[i]))
		{
			free(joined_args);
			return (NULL);
		}
		tmp = ft_strjoin(joined_args, " ");
		free(joined_args);
		joined_args = ft_strjoin(tmp, arv[i]);
		free(tmp);
		i++;
	}
	return (joined_args);
}

int	max_idx(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
