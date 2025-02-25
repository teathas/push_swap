/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:27:10 by aberkass          #+#    #+#             */
/*   Updated: 2025/02/17 16:37:19 by aberkass         ###   ########.fr       */
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
# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				is_in_first_half;
	int				cost;
	int				is_cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//operations
void	pa(t_stack **dst, t_stack **src, char *op);
void	pb(t_stack **dst, t_stack **src, char *op);
void	ra(t_stack **a, char *op);
void	rb(t_stack **b, char *op);
void	rr(t_stack **a, t_stack **b, char *op);
void	sa(t_stack **a, char *op);
void	sb(t_stack **b, char *op);
void	ss(t_stack **a, t_stack **b, char *op);
void	rra(t_stack **a, char *op);
void	rrb(t_stack **b, char *op);
void	rrr(t_stack **a, t_stack **b, char *op);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	re_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

//stack utils
void	fill_stack_a(t_stack **a, char **args);
int		is_sorted(t_stack *s);
int		get_stack_len(t_stack *s);
t_stack	*getlast(t_stack *s);
t_stack	*get_max(t_stack *s);
t_stack	*get_min(t_stack *s);

//general utils
long	ft_atol(const char	*str, t_stack **a, char **args);
void	free_splited(char **splited);
char	*join_args(char **arv, int arc);
int		max_idx(int a, int b);

//errors handling
int		duplicate_check(t_stack *a, int n);
int		syntax_check(char *str);
void	clean_stack(t_stack **s);
void	free_and_exit(t_stack **s, char **args);
int		is_only_white_space(char *str);

//checker
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char const *s2);
int		ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s);
char	*str_append(char *dst, const char *s1, const char *s2);
char	*read_operations(t_stack **a);
void	execute_operations(t_stack **a, t_stack **b, char *op);
void	execute_operation(char *op, t_stack **a, t_stack **b);

#endif
