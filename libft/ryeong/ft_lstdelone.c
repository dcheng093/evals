/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:06:25 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/11 07:03:04 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		if (lst)
			free(lst);
	}
}

/* static void print_int_array(int *array)
{
	for (size_t i = 0; array[i] != 0; i++)
        printf("%d ", array[i]);
	printf("\n");
}

void print_list_content(t_list *head, int node_num)
{
    printf("Node Type: %d\nNode Content: ", node_num);
    if (node_num == 1)
        printf("%s", (char *)head->content);
    else if (node_num == 2)
        printf("%c", *(char *)head->content);
    else if (node_num == 3)
        print_int_array((int *)head->content);
    else if (node_num == 4)
        printf("%d", *(int *)head->content);
	else
		printf("nothing");
    printf("\n");
}

void	test(void *nodecontent)
{
	if (nodecontent)
	{
		free(nodecontent);
	}
}

int main(void)
{
	char ft_lstdelone_string[12] = "hello world";
	char ft_lstdelone_char = '@';
	int ft_lstdelone_intarray[6] = {1,2,3,4,5,0};
	int ft_lstdelone_int = 9;
	

	t_list *head = NULL;
	t_list *node1 = ft_lstnew(&ft_lstdelone_string);
	t_list *node2 = ft_lstnew(&ft_lstdelone_char);
	t_list *node3 = ft_lstnew(&ft_lstdelone_intarray);
	t_list *node4 = ft_lstnew(&ft_lstdelone_int);

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node4);

	char ft_lstdelone_newstring[14] = "commit unalive";
	t_list *node5 = ft_lstnew(ft_strdup(ft_lstdelone_newstring));
	ft_lstadd_back(&head, node5);
	
	printf("========================================\n");
	printf("ft_lstdelone\n");
	printf("========================================\n");
	printf("Content: '%s'\n", ft_lstdelone_string);
	printf("Content: '%c'\n", ft_lstdelone_char);
	printf("Content: ");
	print_int_array((ft_lstdelone_intarray));
	printf("Content: '%d'\n\n", ft_lstdelone_int);
	printf("Content: ");
	print_list_content(node5, 1);

	printf("Result Content: \n");
	ft_lstdelone(node5, test);
	print_list_content(node5, 1);
	printf("--------------------\n");
}
 */