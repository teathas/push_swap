/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:55:17 by aberkass          #+#    #+#             */
/*   Updated: 2024/11/02 21:58:33 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill(char *res, int n, int i)
{
	while (n > 0)
	{
		res[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char		*res;
	int			len;
	int			s;

	s = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		s++;
		n *= -1;
	}
	len = ft_nlen(n);
	res = (char *)malloc((len + s + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (s)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	ft_fill(res, n, len + s - 1);
	res[len + s] = '\0';
	return (res);
}
