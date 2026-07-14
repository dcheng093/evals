/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:26:24 by asyeo             #+#    #+#             */
/*   Updated: 2026/07/14 15:26:24 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// int main(void)
// {
//     t_list *head = ft_lstnew("world");
//     t_list *new_node = ft_lstnew("hello");

//     ft_lstadd_front(&head, new_node);

//     printf("1st node: %s\n", (char *)head->content);
//     printf("2nd node: %s\n", (char *)head->next->content);
//     printf("next of 2nd: %p\n", (void *)head->next->next);

//     t_list *tmp;
//     while (head)
//     {
//         tmp = head->next;
//         free(head);
//         head = tmp;
//     }

//     return (0);
// }
