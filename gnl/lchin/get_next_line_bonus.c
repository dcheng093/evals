/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:16:40 by lchin             #+#    #+#             */
/*   Updated: 2025/12/04 17:19:26 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1) Use a static array of strings to store excess lines of diff fd
2) Read until buffer size, copy into buffer[fd]. Repeat till there is \n.
3) Extract_line: Copy buffer[fd] until \n and return line.
4) Save_leftovers: Copy excess after \n if any, replacing buffer[fd].
5) Buffer[fd] is not empty, repeat Step 2.
*/

#include "get_next_line_bonus.h"

static char	*extract_line(char *src)
{
	int		i;
	char	*line;

	if (!src || !*src)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		line[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*save_leftover(char *line)
{
	int		i;
	int		j;
	char	*leftovers;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	leftovers = malloc(ft_strlen(line + i) + 1);
	if (!leftovers)
		return (NULL);
	while (line[i])
	{
		leftovers[j] = line[i];
		j++;
		i++;
	}
	leftovers[j] = '\0';
	free(line);
	return (leftovers);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(len + 1);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, len + 1);
	free(s1);
	return (result);
}

static char	*read_line(int fd)
{
	ssize_t	bytes;
	char	*tmp;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes = read(fd, tmp, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[bytes] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	while (!buffer[fd] || !ft_strchr(buffer[fd], '\n'))
	{
		tmp = read_line(fd);
		if (!tmp)
			break ;
		buffer[fd] = ft_strjoin(buffer[fd], tmp);
		free(tmp);
		if (!buffer[fd])
			return (NULL);
	}
	if (!buffer[fd] || !*buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = extract_line(buffer[fd]);
	buffer[fd] = save_leftover(buffer[fd]);
	return (line);
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("get_next_line_bonus.c", O_RDONLY);
	line = get_next_line(fd1);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd1);
	}
	close(fd1);
	fd2 = open("get_next_line.c", O_RDONLY);
	line = get_next_line(fd2);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
	}
	close(fd2);
	fd3 = open("get_next_line_utils_bonus.c", O_RDONLY);
	line = get_next_line(fd3);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
	}
	close(fd3);
	return (0);
}
