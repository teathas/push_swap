/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberkass <aberkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:30:33 by aberkass          #+#    #+#             */
/*   Updated: 2024/11/10 22:17:48 by aberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_node(void *content, void *(*f)(void *))
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = (*f)(content);
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*last_node;
	t_list	*new_node;

	res = NULL;
	last_node = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_node = create_node(lst->content, f);
		if (!new_node)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		if (!res)
			res = new_node;
		else
			last_node->next = new_node;
		last_node = new_node;
		lst = lst->next;
	}
	return (res);
}
