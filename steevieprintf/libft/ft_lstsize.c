/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <stee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:12:24 by stee              #+#    #+#             */
/*   Updated: 2025/10/25 16:09:25 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ct;
	t_list	*curr;

	ct = 0;
	curr = lst;
	while (curr != NULL)
	{
		ct++;
		curr = curr->next;
	}
	return (ct);
}
