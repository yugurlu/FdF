/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illustration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:38:32 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/03 18:06:38 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colour(fdf *data, float z_start, float z_end)
{
	if(z_start != 0 || z_end != 0)
		data->colour = 0x00ff00;
	else
		data->colour = 0x0000cc;
}

void	bresenham(fdf *data, float x_start, float y_start, float x_end,
		float y_end)
{
	int		max;
	float	x_way;
	float	y_way;
	float		z_start;
	float		z_end;

	//Z START - Z END
	z_start = data->z_matrix[(int)y_start][(int)x_start];
	z_end = data->z_matrix[(int)y_end][(int)x_end];

	//colour
	colour(data, z_start, z_end);

	//position
	x_start += data->position_x;
	x_end += data->position_x;
	y_start += data->position_y;
	y_end += data->position_y;

	//zoom
	x_start *= data->zoom;
	x_end *= data->zoom;
	y_start *= data->zoom;
	y_end *= data->zoom;

	//3D
	x_start = (x_start - y_start) * cos(1);
	y_start = (x_start + y_start) * sin(1) - (z_start * 4);
	x_end = (x_end - y_end) * cos(1);
	y_end = (x_end + y_end) * sin(1) - (z_end * 4);

	x_way = x_end - x_start;
	y_way = y_end - y_start;
	max = MAX(MOD(x_way), MOD(y_way));
	x_way /= max;
	y_way /= max;
	while ((int)(x_end - x_start) || (int)(y_end - y_start))
	{

		mlx_pixel_put(data->mlx, data->mlx_window, x_start, y_start, data->colour);
		x_start += x_way;
		y_start += y_way;
	}
}

void	illustration(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->height > y)
	{
		x = 0;
		while (data->width > x)
		{
			if(data->width - 1 > x)
				bresenham(data, x, y, x + 1, y);
			if(data->height - 1 > y)
				bresenham(data, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}
