/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/21 11:42:24 by pniezen       #+#    #+#                 */
/*   Updated: 2022/08/01 10:40:56 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->x_offset -= 5.0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->x_offset += 5.0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->y_offset -= 5.0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->y_offset += 5.0;
}

static void	zoom(t_fdf *data)
{
	if (((mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT)
				&& mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
			|| (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT_SHIFT)
				&& mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))))
		data->zoom += 0.75;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS)
		&& (data->zoom / 2) - 0.75 > 0)
		data->zoom -= 0.75;
}

static void	key_hooks_2(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q))
		data->z_scale += 0.025;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->z_scale -= 0.025;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_TAB))
	{
		data->zoom = 30;
		data->z_scale = 0.1;
		data->scr_x = data->mlx->width;
		data->scr_y = data->mlx->height;
		data->isometric = true;
		data->x_offset = data->mlx->width / 2;
		data->y_offset = data->mlx->height / 2;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_1))
		data->isometric = true;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_2))
		data->isometric = false;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		exit_program(data);
}

void	key_hooks(void *param)
{
	t_fdf	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move(data);
	if (((mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT)
				&& mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
			|| (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT_SHIFT)
				&& mlx_is_key_down(data->mlx, MLX_KEY_EQUAL)))
		|| mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
		zoom(data);
	else
		key_hooks_2(data);
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->scr_x, data->scr_y);
	print_image(data, data->z_matrix);
}

void	resize_screen(int32_t width, int32_t height, void *param)
{
	t_fdf	*data;

	data = param;
	data->mlx->width = width;
	data->mlx->height = height;
	data->scr_x = data->mlx->width;
	data->scr_y = data->mlx->height;
	data->x_offset = data->mlx->width / 2;
	data->y_offset = data->mlx->height / 2;
}
