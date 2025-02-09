/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:08:00 by aberkass          #+#    #+#             */
/*   Updated: 2024/11/09 22:18:06 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wc(char const *s, char c)
{
	int	wc;
	int	i;

	wc = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			wc++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (wc);
}

static void	ft_free(char **s, int i)
{
	while (i > 0)
	{
		free(s[--i]);
	}
	free(s);
}

char	**ft_split(char const	*s, char c)
{
	char		**splited;
	int			i;
	int			j;
	size_t		start;

	splited = (char **)malloc((ft_wc(s, c) + 1) * sizeof(char *));
	if (!splited || !s)
		return (free(splited), NULL);
	i = 0;
	j = 0;
	while (s[j] && i < ft_wc(s, c))
	{
		while (s[j] == c && s[j])
			j++;
		start = j;
		while (s[j] != c && s[j])
			j++;
		splited[i++] = ft_substr(s, start, j - start);
		if (!splited[i - 1])
			return (ft_free(splited, i - 1), NULL);
	}
	splited[i] = NULL;
	return (splited);
}
