/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichong <jichong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:20:29 by jichong           #+#    #+#             */
/*   Updated: 2025/11/06 15:24:23 by jichong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst1;

	lst1 = malloc(sizeof(t_list));
	if (!lst1)
		return (NULL);
	lst1->content = content;
	lst1->next = (NULL);
	return (lst1);
}
