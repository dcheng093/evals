/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:07:13 by madinata          #+#    #+#             */
/*   Updated: 2026/07/29 16:17:28 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*cur;

	start = NULL;
	cur = NULL;
	while (lst != NULL)
	{
		if (start == NULL)
		{
			start = ft_lstnew(f(lst->content));
			if (!start)
				return (NULL);
			cur = start;
		}
		else
		{
			cur->next = ft_lstnew(f(lst->content));
			if (cur->next == NULL)
				return (ft_lstclear(&start, del), NULL);
			cur = cur->next;
		}
		lst = lst->next;
	}
	return (start);
}
