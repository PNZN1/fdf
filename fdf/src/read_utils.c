/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:27:53 by pniezen       #+#    #+#                 */
/*   Updated: 2022/08/01 09:57:10 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_color(t_dots *z_matrix, char *z)
{
	z_matrix->z = ft_atoi(z);
	if (z_matrix->z <= -7)
		z_matrix->color = set_color("0x78AB78", 8);
	if (z_matrix->z > -7)
		z_matrix->color = set_color("0xCAFFCA", 8);
	if (z_matrix->z > -5)
		z_matrix->color = set_color("0xACFFAC", 8);
	if (z_matrix->z > -3)
		z_matrix->color = set_color("0x97FF97", 8);
	if (z_matrix->z > -1)
		z_matrix->color = set_color("0x5CFF5C", 8);
	if (z_matrix->z == 0)
		z_matrix->color = set_color("0x00CC00", 8);
	if (z_matrix->z > 1)
		z_matrix->color = set_color("0x00A300", 8);
	if (z_matrix->z > 3)
		z_matrix->color = set_color("0x008200", 8);
	if (z_matrix->z > 5)
		z_matrix->color = set_color("0x006800", 8);
	if (z_matrix->z > 7)
		z_matrix->color = set_color("0xA30000", 8);
	if (z_matrix->z > 9)
		z_matrix->color = set_color("0xCC2900", 8);
}

static uint32_t	hex_to_rgba(int hexvalue, int len)
{
	t_rgba	color;

	if (len == 8)
		hexvalue <<= 8;
	color.rgba_value = hexvalue;
	color.rgba.a = 255;
	return (color.rgba_value);
}

uint32_t	set_color(char *hex, int length)
{
	int	decimal;
	int	base;

	decimal = 0;
	base = 1;
	while (length >= 0)
	{
		if (hex[length] >= '0' && hex[length] <= '9')
		{
			decimal += (hex[length] - 48) * base;
			base *= 16;
		}
		else if (hex[length] >= 'A' && hex[length] <= 'F')
		{
			decimal += (hex[length] - 55) * base;
			base *= 16;
		}
		else if (hex[length] >= 'a' && hex[length] <= 'f')
		{
			decimal += (hex[length] - 87) * base;
			base *= 16;
		}
		length--;
	}
	return (hex_to_rgba(decimal, ft_strlen(hex)));
}
