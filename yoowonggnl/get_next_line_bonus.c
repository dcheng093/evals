/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:50:26 by yoowong           #+#    #+#             */
/*   Updated: 2025/12/16 21:09:46 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_n_store(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1 * sizeof (char));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		temp = stash;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (stash);
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(temp, buffer);
		free (temp);
	}
	free (buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	length;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	length = 0;
	while (stash[length] && stash[length] != '\n')
		length++;
	line = malloc((length + 2) * sizeof(char));
	while (i < length)
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clear_n_save(char *stash)
{
	char	*leftovers;
	size_t	i;
	size_t	length;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	length = ft_strlen(stash) - i - 1;
	i++;
	leftovers = ft_substr(stash, i, length);
	free(stash);
	return (leftovers);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_n_store(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clear_n_save(stash[fd]);
	return (line);
}
