/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:45:07 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/21 13:45:09 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESC:	Takes as a parameter a node and frees the memory of
// 		the node’s content using the function ’del’ given
// 		as a parameter and free the node. The memory of
// 		’next’ must not be freed.

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
