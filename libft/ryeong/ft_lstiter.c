/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:12:02 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/11 08:23:39 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
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
		char *ph = (char *)nodecontent;
		int i = 0;
		while (ph[i])
		{
			ph[i] = ph[i] + 1;
			i++;
		}
	}
}

int main(void)
{
	// char ft_lstiter_string[12] = "hello world";
	// char ft_lstiter_char = '@';
	// int ft_lstiter_intarray[6] = {1,2,3,4,5,0};
	// int ft_lstiter_int = 9;

	t_list *head = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("life any percent"));
	t_list *node2 = ft_lstnew(ft_strdup("initiate rope and chair"));
	t_list *node3 = ft_lstnew(ft_strdup("go 0/1/0 irl"));
	t_list *node4 = ft_lstnew(ft_strdup("30 meter parachuteless skydiving"));

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node4);

	// char ft_lstiter_newstring[14] = "commit unalive";
	t_list *node5 = ft_lstnew(ft_strdup("commit unalive"));
	ft_lstadd_front(&head, node5);
	
	printf("========================================\n");
	printf("ft_lstiter\n");
	printf("========================================\n");
	printf("Content:\n");
	print_list_content(node1, 1);
	print_list_content(node2, 1);
	print_list_content(node3, 1);
	print_list_content(node4, 1);
	print_list_content(node5, 1);

	printf("\nResult Content: \n");
	ft_lstiter(head, test);
	print_list_content(node1, 1);
	print_list_content(node2, 1);
	print_list_content(node3, 1);
	print_list_content(node4, 1);
	print_list_content(node5, 1);
	printf("--------------------\n");
}
 */