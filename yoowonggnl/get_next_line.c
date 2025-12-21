/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoowong <yoowong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:02:16 by yoowong           #+#    #+#             */
/*   Updated: 2025/11/25 15:02:17 by yoowong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_n_store(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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
		stash = ft_strjoin(stash, buffer);
		free (temp);
	}
	free (buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	idx;

	if (stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	idx = 0;
	while (idx < i)
	{
		line[idx] = stash[idx];
		idx++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_n_save(char *stash)
{
	char			*leftovers;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	leftovers = NULL;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] != '\0')
	{
		i++;
		len = (unsigned int)ft_strlen(stash) - i;
		leftovers = ft_substr(stash, i, len);
		free(stash);
		return (leftovers);
	}
	free(stash);
	return (leftovers);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_n_store (fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_n_save(stash);
	return (line);
}
