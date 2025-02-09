/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:56:29 by aberkass          #+#    #+#             */
/*   Updated: 2024/11/09 22:09:54 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isin(char const	*str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*new;
	size_t		new_size;

	while (*s1 && ft_isin(set, *s1))
	{
		s1++;
	}
	new_size = ft_strlen(s1);
	while (new_size && ft_isin(set, s1[new_size - 1]))
	{
		new_size--;
	}
	new = (char *)malloc(new_size + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, new_size + 1);
	return (new);
}
