/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 15:58:09 by pniezen       #+#    #+#                 */
/*   Updated: 2022/04/12 11:59:49 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	set_zero(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

static char	*get_one_line(char *src)
{
	char	*tmp;
	int		i;

	if (!src)
		return (free_null(src));
	tmp = ft_calloc(get_ft_strlen(src) + 1, sizeof(char));
	if (!tmp)
	{
		free(src);
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		tmp[i] = src[i];
		if (src[i] == '\n')
			break ;
		i++;
	}
	free(src);
	return (tmp);
}

static char	*read_to_return(int fd, char *return_line)
{
	ssize_t	rd_fd;
	char	*buffer;

	rd_fd = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (free_null(return_line));
	}
	while (!(check_new_line(return_line)) && rd_fd > 0)
	{
		rd_fd = read(fd, buffer, BUFFER_SIZE);
		if (rd_fd <= 0 && return_line[0] == '\0')
		{
			free(return_line);
			return (free_null(buffer));
		}
		return_line = realloc_and_join(return_line, buffer);
		set_zero(buffer);
	}
	free(buffer);
	return (return_line);
}

static void	set_storage(char *storage, char *return_line)
{
	int	i;
	int	j;

	i = 0;
	while (return_line[i] != '\n' && return_line[i])
		i++;
	if (return_line[i] != '\0')
		i++;
	j = 0;
	while (return_line[i])
	{
		storage[j] = return_line[i];
		i++;
		j++;
	}
	storage[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	storage[OPEN_MAX][BUFFER_SIZE + 1];
	char		*return_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	return_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!return_line)
		return (NULL);
	return_line = realloc_and_join(return_line, storage[fd]);
	if (!return_line)
		return (NULL);
	return_line = read_to_return(fd, return_line);
	if (return_line)
		set_storage(storage[fd], return_line);
	return_line = get_one_line(return_line);
	return (return_line);
}
