/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 09:06:56 by pniezen       #+#    #+#                 */
/*   Updated: 2022/08/01 10:10:57 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "MLX42/MLX42.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1080

// data structs
typedef union u_rgba
{
	uint32_t	rgba_value;
	struct s_rgba
	{
		uint8_t	a;
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
	}	rgba;
}	t_rgba;

typedef struct s_dots
{
	float		x;
	float		y;
	int			z;
	uint32_t	color;
}	t_dots;

typedef struct s_fdf
{
	int			width;
	int			height;
	t_dots		**z_matrix;
	float		zoom;
	double		z_scale;
	bool		isometric;
	int			scr_x;
	int			scr_y;

	float		x_offset;
	float		y_offset;

	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_fdf;

// read_file, read_utils
bool		read_file(char *file, t_fdf *data);
void		get_color(t_dots *z_matrix, char *z);
uint32_t	set_color(char *hex, int length);

// key_hook
void		key_hooks(void *param);
void		resize_screen(int32_t width, int32_t height, void *param);

// image_print
void		print_image(t_fdf *data, t_dots **z_matrix);

// bresen_ham
void		bresenham(t_dots start, t_dots end, t_fdf *data);

// utils
void		first_init(t_fdf *data);
void		free_dp_char(char **str);
void		exit_on_error(int err_num, char *msg);
void		exit_program(void *param);

#endif
