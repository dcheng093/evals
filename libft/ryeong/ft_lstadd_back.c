/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:23:32 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/11 09:25:49 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ph;

	ph = ft_lstlast(*lst);
	if (!ph)
		*lst = new;
	else
		ph->next = new;
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
    printf("\n");
}

int main(void)
{
	char ft_lstaddback_string[12] = "hello world";
	char ft_lstaddback_char = '@';
	int ft_lstaddback_intarray[6] = {1,2,3,4,5,0};
	int ft_lstaddback_int = 9;
	

	t_list *head = NULL;
	t_list *node1 = ft_lstnew(&ft_lstaddback_string);
	t_list *node2 = ft_lstnew(&ft_lstaddback_char);
	t_list *node3 = ft_lstnew(&ft_lstaddback_intarray);
	t_list *node4 = ft_lstnew(&ft_lstaddback_int);

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node4);

	char ft_lstaddback_newstring[14] = "commit unalive";
	t_list *node5 = ft_lstnew(&ft_lstaddback_newstring);
	ft_lstadd_back(&head, node5);
	
	printf("========================================\n");
	printf("ft_lstaddback\n");
	printf("========================================\n");
	printf("Content: '%s'\n", ft_lstaddback_string);
	printf("Content: '%c'\n", ft_lstaddback_char);
	printf("Content: ");
	print_int_array((ft_lstaddback_intarray));
	printf("Content: '%d'\n\n", ft_lstaddback_int);

	printf("Result Content: \n");
	print_list_content(node5, 1);
	printf("--------------------\n");
}
 */