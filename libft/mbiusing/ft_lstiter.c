/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:48:35 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/18 11:40:37 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESC :	Iterates the list ’lst’ and applies the function
// 		’f’ on the content of each node.

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
