/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:08:18 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/11 20:18:59 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*back_s1;

	if (!s1)
		return (ft_strdup(""));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	back_s1 = (char *)(s1 + ft_strlen(s1) - 1);
	while (back_s1 > s1 && ft_strchr(set, *back_s1))
		back_s1--;
	return (ft_substr(s1, 0, (back_s1 - s1 + 1)));
}
/*int			main()

{
char	*s1 = "asasasasHello Worldasasasas";
char	*set ="as";
printf("%s\n" , ft_strtrim(s1, set));

return (0);

}*/
