/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:16:23 by lchin             #+#    #+#             */
/*   Updated: 2025/12/04 17:15:33 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1) Read until buffer size, copy into line. Repeat till there is \n in line.
2) Save_leftovers: Copy excess after \n if any into buffer.
3) Extract_line: Copy line until \n and return line.
4) Buffer is not empty, add buffer into line. 
5) Repeat step 1.
Using static string for leftovers, so its value remains throughout the program.
*/

#include "get_next_line.h"

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

static void	save_leftover(char *line, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i])
	{
		buffer[j] = line[i];
		j++;
		i++;
	}
	buffer[j] = '\0';
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
	static char	buffer[BUFFER_SIZE + 1];
	char		*tmp;
	char		*line;
	char		*result;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (*buffer)
		line = ft_strjoin(line, buffer);
	while (!line || !ft_strchr(line, '\n'))
	{
		tmp = read_line(fd);
		if (!tmp)
			break ;
		line = ft_strjoin(line, tmp);
		free(tmp);
	}
	if (!line || !*line)
		return (free(line), NULL);
	save_leftover(line, buffer);
	result = extract_line(line);
	free(line);
	return (result);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("get_next_line.c", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
