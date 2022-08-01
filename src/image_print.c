/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_print.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/21 11:42:35 by pniezen       #+#    #+#                 */
/*   Updated: 2022/08/01 10:11:19 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_image(t_fdf *data, t_dots **z_matrix)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if ((x + 1) < data->width)
				bresenham(z_matrix[y][x], z_matrix[y][x + 1], data);
			if ((y + 1) < data->height)
				bresenham(z_matrix[y][x], z_matrix[y + 1][x], data);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
