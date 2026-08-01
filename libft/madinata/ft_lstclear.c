/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:22:56 by madinata          #+#    #+#             */
/*   Updated: 2026/07/31 21:26:58 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*next;

	if (!lst)
		return ;
	next = *lst;
	while (next != NULL)
	{
		cur = next;
		next = cur->next;
		ft_lstdelone(cur, del);
	}
	*lst = 0;
}
