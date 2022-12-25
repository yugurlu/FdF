/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illustration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:38:32 by yugurlu           #+#    #+#             */
/*   Updated: 2022/12/25 18:41:34 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	bresenham(fdf *data, float x_start, float y_start, float x_end,
		float y_end)
{
	int		max;
	float	x_way;
	float	y_way;
	int		z_start;

	z_start = data->z_matrix[(int)y_start][(int)x_start];
	data->colour = ((z_start != 0) ? 0x00ffcc : 0xffffff);
	x_start *= data->zoom;
	x_end *= data->zoom;
	y_start *= data->zoom;
	y_end *= data->zoom;
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
	data->zoom = 20;
	while (data->height > y)
	{
		x = 0;
		while (data->width > x)
		{
			if(data->width - 1 > x)
				bresenham(data, x, y, x + 1, y);
			if(data->height - 1> y)
				bresenham(data, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}
