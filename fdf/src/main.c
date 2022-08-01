/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 09:06:25 by pniezen       #+#    #+#                 */
/*   Updated: 2022/08/01 10:55:28 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <sys/errno.h>

static bool	file_check(char *format)
{
	int	i;
	int	size;

	size = ft_strlen(format);
	i = size - 4;
	if (!ft_strnstr(format, ".fdf", size))
		exit_on_error(EFTYPE, "Wrong file format. Does it end with .fdf ?");
	return (false);
}

static bool	check_read(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit_on_error(ENOENT, "Could not open file in 'check_read'");
	return (false);
}

static void	print_menu(t_fdf *data)
{
	int	y;

	y = 0;
	mlx_put_string(data->mlx, "Move: ^ | v ", 15, y += 30);
	mlx_put_string(data->mlx, "Move: <- | -> ", 15, y += 30);
	mlx_put_string(data->mlx, "Zoom: + | - ", 15, y += 30);
	mlx_put_string(data->mlx, "Scale: Q | W ", 15, y += 30);
	mlx_put_string(data->mlx, "Reset: TAB ", 15, y += 30);
	mlx_put_string(data->mlx, "ISO ON/OFF: 1 | 2 ", 15, y += 30);
	mlx_put_string(data->mlx, "Exit: ESC ", 15, y += 30);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		exit_on_error(EINVAL, "Example './fdf file.fdf' ");
	file_check(argv[1]);
	check_read(argv[1]);
	data = malloc(sizeof(t_fdf));
	if (!data)
		exit_on_error(ENOMEM, "Memory allocation error in 'main'");
	read_file(argv[1], data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "fil de fer", true);
	first_init(data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	print_menu(data);
	print_image(data, data->z_matrix);
	mlx_loop_hook(data->mlx, key_hooks, data);
	mlx_resize_hook(data->mlx, resize_screen, data);
	mlx_close_hook(data->mlx, exit_program, data);
	mlx_loop(data->mlx);
	return (0);
}
