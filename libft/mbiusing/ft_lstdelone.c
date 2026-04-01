/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:02:02 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/18 11:40:31 by mbiusing         ###   ########.fr       */
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
