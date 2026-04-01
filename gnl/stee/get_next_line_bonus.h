/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <stee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:43:28 by stee              #+#    #+#             */
/*   Updated: 2025/11/07 13:43:30 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*ft_append(char **s_line, char *buffer, int bytes);
char	*ft_readline(int fd, char **s_line);
char	*ft_extract(char *s_line);
char	*ft_clearbuffer(char *s_line);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#endif
