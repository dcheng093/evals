/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:10:46 by jia-liew          #+#    #+#             */
/*   Updated: 2026/08/02 16:10:48 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next_node;

	if (!lst || !f)
		return ;
	next_node = lst->next;
	while (next_node)
	{
		next_node = lst->next;
		f(lst->content);
		lst = next_node;
	}
}
