/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:27:10 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/28 20:27:12 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../push_swap.h"

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char const *s2);
int		ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s);
char	*str_append(char *dst, const char *s1, const char *s2);
void	execute_operation(char *op, t_stack **a, t_stack **b);
#endif
