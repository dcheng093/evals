/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:42:44 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/18 11:41:56 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESC	:	Iterates the list ’lst’ and applies the function
// 			’f’ on the content of each node. Creates a new
// 			list resulting of the successive applications of
// 			the function ’f’. The ’del’ function is used to
// 			delete the content of a node if needed.

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	node = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}
