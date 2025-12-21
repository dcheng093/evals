/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <stee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:43:28 by stee              #+#    #+#             */
/*   Updated: 2025/11/07 13:43:30 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_append(char **s_line, char *buffer, int bytes)
{
	char	*temp_line;

	if (!*s_line)
	{
		*s_line = ft_strdup("");
		if (!*s_line)
			return (NULL);
	}
	if (bytes > 0)
	{
		buffer[bytes] = '\0';
		temp_line = ft_strjoin(*s_line, buffer);
		if (!temp_line)
			return (NULL);
		free (*s_line);
		*s_line = temp_line;
	}
	return (*s_line);
}

char	*ft_readline(int fd, char **s_line)
{
	char	*buffer;
	int		bytes;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!ft_append(s_line, NULL, 0))
		return (free(buffer), NULL);
	bytes = 1;
	while (!ft_strchr(*s_line, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0 || !ft_append(s_line, buffer, bytes))
			return (free(buffer), NULL);
	}
	free(buffer);
	if (!*s_line || !**s_line)
		return (free(*s_line), *s_line = NULL, NULL);
	return (*s_line);
}

char	*ft_extract(char *s_line)
{
	size_t	end;

	if (!s_line)
		return (NULL);
	end = 0;
	while (s_line[end] != '\0' && s_line[end] != '\n')
		end++;
	if (s_line[end] == '\n')
		end++;
	return (ft_substr(s_line, 0, end));
}

char	*ft_clearbuffer(char *s_line)
{
	size_t	i;
	char	*n_s_line;

	if (!s_line)
		return (NULL);
	i = 0;
	while (s_line[i] != '\0' && s_line[i] != '\n')
		i++;
	if (s_line[i] == '\n')
		i++;
	if (s_line[i] == '\0')
		return (free(s_line), NULL);
	n_s_line = ft_substr(s_line, i, ft_strlen(s_line) - i);
	free(s_line);
	return (n_s_line);
}

char	*get_next_line(int fd)
{
	static char	*s_line[_SC_OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!ft_readline(fd, &s_line[fd]))
		return (NULL);
	line = ft_extract(s_line[fd]);
	s_line[fd] = ft_clearbuffer(s_line[fd]);
	return (line);
}
