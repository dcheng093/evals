/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:03:34 by mmerican          #+#    #+#             */
/*   Updated: 2025/12/31 19:16:24 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

// Define the default buffer size. This way, the code will compile
// ...even without the -D BUFFER_SIZE=n flag.
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

// Functions in this file
char		*get_next_line(int fd);
static char	*read_stuff(int fd);
static int	try_read(char *buffer, int *buffer_end, int fd);
static char	*check_result(char *result);

// Functions I need for this to work
char		*ft_substr(char *str, int start, int end);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(const char *s1, const char *s2);
int			str_has_newline(const char *str);

char	*get_next_line(int fd)
{
	char	*result;
	char	*temp;
	char	*readstuff_result;
	int		stop;

	result = malloc(sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	readstuff_result = read_stuff(fd);
	if (readstuff_result == NULL)
		return (free(result), NULL);
	while (readstuff_result != NULL)
	{
		stop = str_has_newline(readstuff_result);
		temp = result;
		result = ft_strjoin(temp, readstuff_result);
		free(temp);
		free(readstuff_result);
		temp = NULL;
		if (stop)
			break ;
		readstuff_result = read_stuff(fd);
	}
	return (result);
}

static char	*read_stuff(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_index = 0;
	static int	buffer_end = 0;
	int			i;
	char		*result;

	if (buffer_index == buffer_end)
	{
		buffer_index = 0;
		buffer_end = 0;
	}
	if (try_read(buffer, &buffer_end, fd) == -1)
		return (NULL);
	i = buffer_index;
	while (i < buffer_end && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	result = ft_substr(buffer, buffer_index, i);
	buffer_index = i;
	return (check_result(result));
}

// Checks if a read is necessary, and if so, tries to read.
// Returns 0 if no read was needed,
// -1 if the read failed,
// and 1 if it succeeded.
static int	try_read(char *buffer, int *buffer_end, int fd)
{
	if (*buffer_end != 0)
		return (0);
	*buffer_end = read(fd, buffer, BUFFER_SIZE);
	if (*buffer_end <= 0)
		return (-1);
	if (*buffer_end < BUFFER_SIZE)
		buffer[*buffer_end] = '\0';
	return (1);
}

static char	*check_result(char *result)
{
	if (result == NULL)
		return (result);
	if (ft_strlen(result) == 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}


// #include <stdio.h>
// int main()
// {
//     char *line;
//     int line_index = 0;

//     while((line = get_next_line(0))) {
//         printf("%d: ", ++line_index);
//         for (int i = 0; line[i]; i++) {
//             if(line[i] == '\n')
//                 printf("\x1b[2m\\n\n\x1b[0m");
//             else
//                 printf("%c", line[i]);
            
//         }
//         free(line);
//         fflush(stdout);
//     }
// }

