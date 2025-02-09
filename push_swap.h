/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:25:26 by aberkass          #+#    #+#             */
/*   Updated: 2025/01/16 20:25:29 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

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
void	set_b_nodes(t_stack *a, t_stack *b);
t_stack	*get_cheapest(t_stack *s);
void	set_positions(t_stack *s);
void	prepare_for_push(t_stack **s, t_stack *top, char s_name);
int	get_middle_element(t_stack *a);

//general utils
long	ft_atol(const char	*str);
void	free_splited(char **splited);
char	*join_args(char **arv, int arc);

//sorting
void	sort_small_stack(t_stack **a, t_stack **b, int size);
void	sort_big_stack(t_stack **a, t_stack **b);
void	sort_for_three(t_stack **s);
void	sort(t_stack **a, t_stack **b);

//errors handling
int		duplicate_check(t_stack *a, int n);
int		syntax_check(char *str);
void	clean_stack(t_stack **s);
void	free_and_exit(t_stack **s);

#endif
