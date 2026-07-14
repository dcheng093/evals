/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:30:46 by asyeo             #+#    #+#             */
/*   Updated: 2026/07/14 15:30:46 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*extract_line(char **save)
{
	char	*line;
	char	*tmp;
	ssize_t	len;

	len = 0;
	if (!*save || !**save)
		return (NULL);
	while ((*save)[len] && (*save)[len] != '\n')
		len++;
	line = ft_substr_gnl(*save, 0, len + ((*save)[len] == '\n'));
	if (!line)
		return (NULL);
	tmp = ft_strdup_gnl(*save + len + ((*save)[len] == '\n'));
	free(*save);
	*save = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*buff;
	ssize_t		bytes;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr_gnl(save[fd], '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			return (free(buff), NULL);
		}
		buff[bytes] = '\0';
		save[fd] = ft_strjoin_gnl(save[fd], buff, bytes);
	}
	return (free(buff), extract_line(&save[fd]));
}
