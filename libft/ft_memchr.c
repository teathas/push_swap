/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:43:21 by aberkass          #+#    #+#             */
/*   Updated: 2024/10/28 10:44:55 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_t;
	unsigned char	ch;
	size_t			i;

	i = 0;
	s_t = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (s_t[i] == ch)
			return ((void *)&s_t[i]);
		i++;
	}
	return (NULL);
}
