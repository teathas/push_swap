/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:26:24 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/28 20:27:39 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_get_line(char *str)
{
	int		i;
	int		size;
	char	*line;

	size = 0;
	if (*str == '\0')
		return (NULL);
	while (str[size] && str[size] != '\n')
		size++;
	if (str[size] == '\n')
		size++;
	line = malloc(size + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_remain(char	*str)
{
	int		i;
	int		j;
	char	*remain;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	if (!str[i])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	remain = malloc(ft_strlen_gnl(&str[i]) + 1);
	if (!remain)
		return (NULL);
	while (str[i])
		remain[j++] = str[i++];
	remain[j] = '\0';
	free(str);
	str = NULL;
	return (remain);
}

int	nl_check(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	read_file(int fd, char **buffer)
{
	char	*buff;
	int		readed;

	readed = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (0);
	while (!nl_check(*buffer) && readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			return (0);
		}
		buff[readed] = '\0';
		*buffer = ft_strjoin_gnl(*buffer, buff);
		if (*buffer == NULL)
		{
			free(buff);
			return (0);
		}
	}
	free(buff);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_file(fd, &buffer))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (buffer != NULL)
	{
		line = ft_get_line(buffer);
		buffer = ft_get_remain(buffer);
		if (buffer == NULL)
			free(buffer);
	}
	return (line);
}
