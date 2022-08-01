/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresen_ham.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 10:09:40 by pniezen       #+#    #+#                 */
/*   Updated: 2022/08/01 10:10:45 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	get_zoom(t_dots *start, t_dots *end, t_fdf *data)
{
	start->x *= data->zoom;
	start->y *= data->zoom;
	start->z *= data->z_scale * data->zoom;
	end->x *= data->zoom;
	end->y *= data->zoom;
	end->z *= data->z_scale * data->zoom;
}

static void	ft_isometric(float *x, float *y, int z, t_fdf *data)
{
	if (data->isometric)
	{
		*x = (*x - *y) * cos(120.0);
		*y = (*x + *y) * sin(120.0) - z;
	}
}

static void	get_offset(t_dots *start, t_dots *end, t_fdf *data)
{
	start->x += data->x_offset;
	start->y += data->y_offset;
	end->x += data->x_offset;
	end->y += data->y_offset;
}

static void	pixel_print(t_dots start, t_dots end, t_fdf *data)
{
	if ((start.x < data->scr_x && start.y < data->scr_y
			&& start.y > 0 && start.x > 0))
		mlx_put_pixel(data->img, start.x, start.y, start.color);
	if ((end.x < data->scr_x && end.y < data->scr_y
			&& end.y > 0 && end.x > 0))
		mlx_put_pixel(data->img, end.x, end.y, start.color);
}

void	bresenham(t_dots start, t_dots end, t_fdf *data)
{
	float	max;
	float	x_step;
	float	y_step;

	get_zoom(&start, &end, data);
	ft_isometric(&start.x, &start.y, start.z, data);
	ft_isometric(&end.x, &end.y, end.z, data);
	get_offset(&start, &end, data);
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	if (start.z < end.z)
		start.color = end.color;
	while (true)
	{
		pixel_print(start, end, data);
		if (!(int)(end.x - start.x) && !(int)(end.y - start.y))
			break ;
		start.x += x_step;
		start.y += y_step;
	}
}
