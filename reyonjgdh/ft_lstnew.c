/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:23:32 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/11 09:20:23 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* static void print_int_array(int *array)
{
	for (size_t i = 0; array[i] != 0; i++)
        printf("%d ", array[i]);
	printf("\n");
}

int main(void)
{
	char ft_lstnew_string[12] = "hello world";
	char ft_lstnew_char = '@';
	int ft_lstnew_intarray[6] = {1,2,3,4,5,0};
	int ft_lstnew_int = 9;

	t_list *node1 = ft_lstnew(&ft_lstnew_string);
	t_list *node2 = ft_lstnew(&ft_lstnew_char);
	t_list *node3 = ft_lstnew(&ft_lstnew_intarray);
	t_list *node4 = ft_lstnew(&ft_lstnew_int);

	printf("========================================\n");
	printf("ft_lstnew\n");
	printf("========================================\n");
	printf("Content: '%s'\n\n", ft_lstnew_string);

	printf("Result Content: %s\n", (char *)node1->content);
	printf("Result Next: %p\n", (void *)node1->next);
	printf("--------------------\n");

	printf("Content: '%c'\n\n", ft_lstnew_char);

	printf("Result Content: %c\n", *(char *)node2->content);
	printf("Result Next: %p\n", (void *)node2->next);
	printf("--------------------\n");

	printf("Content: ");
	print_int_array((ft_lstnew_intarray));
	printf("\n");
	printf("Result Content: ");
	print_int_array(((int *)node3->content));
	printf("Result Next: %p\n", (void *)node3->next);
	printf("--------------------\n");

	printf("Content: '%d'\n\n", ft_lstnew_int);

	printf("Result Content: %d\n", *(int *)node4->content);
	printf("Result Next: %p\n", (void *)node4->next);
	printf("--------------------\n");
}
 */