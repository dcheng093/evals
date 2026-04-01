/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <stee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:41:29 by stee              #+#    #+#             */
/*   Updated: 2025/10/21 19:08:56 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = temp;
	}
	*lst = NULL;
}
