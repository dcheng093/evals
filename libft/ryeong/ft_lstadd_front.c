/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:23:32 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/11 09:19:18 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
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
    printf("Node %d: ", node_num);
    if (node_num == 1)
        printf("%s", (char *)head->content);
    else if (node_num == 2)
        printf("%c", *(char *)head->content);
    else if (node_num == 3)
        print_int_array((int *)head->content);
    else if (node_num == 4)
        printf("%d", *(int *)head->content);
    printf("\n");
    // head = head->next;
}

int main(void)
{
	char ft_lstaddfront_string[12] = "hello world";
	char ft_lstaddfront_char = '@';
	int ft_lstaddfront_intarray[6] = {1,2,3,4,5,0};
	int ft_lstaddfront_int = 9;

	t_list *head = NULL;
	t_list *node1 = ft_lstnew(&ft_lstaddfront_string);
	t_list *node2 = ft_lstnew(&ft_lstaddfront_char);
	t_list *node3 = ft_lstnew(&ft_lstaddfront_intarray);
	t_list *node4 = ft_lstnew(&ft_lstaddfront_int);

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node4);
	printf("========================================\n");
	printf("ft_lstaddfront\n");
	printf("========================================\n");
	printf("Content: '%s'\n", ft_lstaddfront_string);
	printf("Content: '%c'\n", ft_lstaddfront_char);
	printf("Content: ");
	print_int_array((ft_lstaddfront_intarray));
	printf("Content: '%d'\n\n", ft_lstaddfront_int);

	printf("Result Content: \n");
	print_list_content(node1, 1);
	print_list_content(node2, 2);
	print_list_content(node3, 3);
	print_list_content(node4, 4);
	printf("--------------------\n");
}
 */