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
	int		read_line;
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
			return (free(buffer), NULL);
		else if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
	}
	free(buffer);
	return (stash);
}

static char	*ft_set_line(char *stash)
{
	char	*line;
	char	*new_line;

	new_line = ft_strchr(stash, '\n');
	if (new_line != NULL)
	.......
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_set_line(stash);
	if (!line)
		return (NULL);
	free(stash); // ????
	return (line);
}
