/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/20 09:51:48 by pniezen       #+#    #+#                 */
/*   Updated: 2022/08/01 10:54:03 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/errno.h>

void	first_init(t_fdf *data)
{
	data->zoom = 30;
	data->z_scale = 0.1;
	data->scr_x = data->mlx->width;
	data->scr_y = data->mlx->height;
	data->isometric = true;
	data->x_offset = data->mlx->width / 2;
	data->y_offset = data->mlx->height / 2;
}

void	free_dp_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	exit_on_error(int err_num, char *msg)
{
	errno = err_num;
	perror(msg);
	exit(EXIT_FAILURE);
}

void	exit_program(void *param)
{
	t_fdf	*data;

	data = param;
	mlx_close_window(data->mlx);
	mlx_delete_image(data->mlx, data->img);
	exit(EXIT_SUCCESS);
}
