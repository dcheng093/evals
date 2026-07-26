/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:38:26 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/21 17:15:27 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC : allocates memory, fills it with zeroes and returns a pointer to it
*/

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memalloced;
	size_t	actualsize;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	actualsize = nmemb * size;
	memalloced = malloc(actualsize);
	if (!memalloced)
		return (NULL);
	ft_bzero(memalloced, actualsize);
	return (memalloced);
}
