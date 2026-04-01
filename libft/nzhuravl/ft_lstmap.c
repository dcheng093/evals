/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuravl <nzhuravl@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 19:58:18 by nzhuravl          #+#    #+#             */
/*   Updated: 2025/12/21 19:58:21 by nzhuravl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_cont;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_cont = f(lst->content);
		new_node = ft_lstnew(new_cont);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
void	*duplicate_str(void *content)
{
	char *str = (char *)content;
	return (ft_strdup(str));
}

void	del_str(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *a = ft_lstnew(ft_strdup("one"));
	t_list *b = ft_lstnew(ft_strdup("two"));
	t_list *c = ft_lstnew(ft_strdup("three"));

	a->next = b;
	b->next = c;

	t_list *mapped = ft_lstmap(a, duplicate_str, del_str);

	t_list *tmp = mapped;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	ft_lstclear(&a, del_str);
	ft_lstclear(&mapped, del_str);
	return (0);
}*/
