/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:44:07 by ryeong            #+#    #+#             */
/*   Updated: 2026/01/14 17:35:01 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

char	*update_stash(char *oldstash, char	*buffer)
{
	char	*newstash;

	if (oldstash == NULL)
		newstash = ft_strdup(buffer);
	else
	{
		newstash = ft_strjoin(oldstash, buffer);
	}
	free (oldstash);
	return (newstash);
}

char	*stash_remove_prev_text(char *oldstash)
{
	char	*newstash;
	int		i;

	if (!oldstash)
		return (NULL);
	i = 0;
	while (oldstash[i] && oldstash[i] != '\n')
		i++;
	if (oldstash[i] == '\n')
		i++;
	if (oldstash[i] == '\0')
	{
		free(oldstash);
		return (NULL);
	}
	newstash = ft_strdup(oldstash + i);
	free (oldstash);
	return (newstash);
}

char	*extract_stash_one_line(char *stash)
{
	size_t	i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

void	norm_mainloop(int *readfilebytes, char *buffer, char **stash, int fd)
{
	while (*readfilebytes > 0)
	{
		buffer[*readfilebytes] = '\0';
		stash[fd] = update_stash(stash[fd], buffer);
		if (ft_strchr(stash[fd], '\n'))
			break ;
		*readfilebytes = read(fd, buffer, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	int			readfilebytes;
	char		*buffer;
	static char	*stash[1000];
	char		*result;

	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readfilebytes = read(fd, buffer, BUFFER_SIZE);
	if (readfilebytes < 0)
		return (free(buffer), NULL);
	else if (readfilebytes == 0 && (!stash[fd] || stash[fd][0] == '\0'))
		return (free(buffer), NULL);
	norm_mainloop(&readfilebytes, buffer, stash, fd);
	result = extract_stash_one_line(stash[fd]);
	stash[fd] = stash_remove_prev_text(stash[fd]);
	free(buffer);
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *file1 = "test1.txt";
// 	char *file2 = "test2.txt";
// 	char *file3 = "test3.txt";
// 	int fd1 = open(file1, O_RDONLY);
// 	int fd2 = open(file2, O_RDONLY);
// 	int fd3 = open(file3, O_RDONLY);
// 	char *string1;
// 	char *string2;
// 	char *string3;
// 	int i = 1;

// 	printf("========================================\n");
// 	printf("get_next_line\n");
// 	printf("===============a=========================\n");

// 	while (i <= 5)
// 	{
// 		printf("---------------------------------\n");
// 		printf("|	Function Call %d		|\n", i);
// 		printf("---------------------------------\n\n");
// 		printf("===== %s =====\n", file1);
// 		string1 = get_next_line(fd1);
// 		printf("|%s|\n", string1);
// 		free(string1);
// 		printf("===== %s =====\n", file2);
// 		string2 = get_next_line(fd2);
// 		printf("|%s|\n", string2);
// 		free(string2);
// 		printf("===== %s =====\n", file3);
// 		string3 = get_next_line(fd3);
// 		printf("|%s|\n", string3);
// 		free(string3);
// 		printf("===== fd -1 =====\n");
// 		string3 = get_next_line(-1);
// 		printf("|%s|\n", string3);
// 		free(string3);
// 		printf("::::::::::::::::::::::::::::::::::::::::\n");
// 		i++;
// 	}
// }
