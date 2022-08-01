/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:27:53 by pniezen       #+#    #+#                 */
/*   Updated: 2022/08/01 10:55:16 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <sys/errno.h>

static void	fill_matrix(t_fdf *data, t_dots *z_matrix, char *line, int y)
{
	char	**nums;
	char	**colors;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		if (!ft_strchr(nums[i], ','))
			get_color(&z_matrix[i], nums[i]);
		else
		{
			colors = ft_split(nums[i], ',');
			z_matrix[i].z = ft_atoi(colors[0]);
			z_matrix[i].color = set_color(colors[1], ft_strlen(colors[1]));
			free_dp_char(colors);
		}
		z_matrix[i].x = i - (data->width / 2);
		z_matrix[i].y = y - (data->height / 2);
		i++;
	}
	free_dp_char(nums);
}

static bool	init_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	data->z_matrix = malloc(sizeof(t_dots *) * (data->height + 1));
	if (!data->z_matrix)
		exit_on_error(ENOMEM, "Memory allocation error in 'init_matrix'");
	while (i < data->height)
	{
		data->z_matrix[i] = malloc(sizeof(t_dots) * (data->width + 1));
		if (!data->z_matrix[i])
			exit_on_error(ENOMEM, "Memory allocation error in 'init_matrix'");
		i++;
	}
	return (true);
}

static char	**split_line(int fd)
{
	char	*line;
	char	*trimmed;
	char	**split;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	trimmed = ft_strtrim(line, " \n");
	free(line);
	if (!trimmed)
		return (NULL);
	split = ft_split(trimmed, ' ');
	free(trimmed);
	if (!split)
		return (NULL);
	return (split);
}

static bool	get_width_height(t_fdf *data, char *file)
{
	int		fd;
	int		width;
	int		heigth;
	char	**line_split;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_on_error(ENOENT, "Could not open file in 'get_width_height'");
	heigth = 0;
	while (true)
	{
		line_split = split_line(fd);
		if (!line_split)
			break ;
		width = 0;
		while (line_split[width])
			width++;
		free_dp_char(line_split);
		heigth++;
	}
	data->width = width;
	data->height = heigth;
	close(fd);
	return (true);
}

bool	read_file(char *file, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_on_error(ENOENT, "Could not open file in 'read_file'");
	if (!get_width_height(data, file) || !init_matrix(data))
		return (false);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data, data->z_matrix[i], line, i);
		free(line);
		i++;
	}
	close(fd);
	return (true);
}
