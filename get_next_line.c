/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:53:48 by maiferna          #+#    #+#             */
/*   Updated: 2024/10/14 13:54:04 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *stash)
{
	ssize_t	read_line;
	char	*buffer;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_line = 1;
	if (!stash)
		stash = ft_strdup("");
	while (read_line > 0 && !ft_strchr(stash, '\n'))
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line < 0)
			return (free(buffer), free(stash), NULL);
		if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		if (!stash)
			return (free(buffer), free(stash), NULL);
	}
	return (free(buffer), stash);
}

static char	*ft_set_line(char *stash)
{
	size_t	i;
	char	*new_line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	new_line = ft_substr(stash, 0, i + (stash[i] == '\n'));
	if (!new_line)
		return (NULL);
	return (new_line);
}

static char	*ft_update(char *stash)
{
	size_t	i;
	char	*remainder;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	remainder = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	free(stash);
	if (!remainder || remainder[0] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_set_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_update(stash);
	return (line);
}
