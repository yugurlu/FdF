/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illustration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:38:32 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/06 08:21:20 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(fdf *data, float x_start, float y_start, float x_end, float y_end,
		float x_way, float y_way)
{
	while ((int)(x_end - x_start) || (int)(y_end - y_start))
	{
		mlx_pixel_put(data->mlx, data->mlx_window, x_start, y_start,
				data->colour);
		x_start += x_way;
		y_start += y_way;
	}
}

void	algorithm(fdf *data, float x_start, float y_start, float x_end,
		float y_end)
{
	float	x_way;
	float	y_way;
	float	z_start;
	float	z_end;

	z_start = data->z_matrix[(int)y_start][(int)x_start];
	z_end = data->z_matrix[(int)y_end][(int)x_end];
	colour(data, z_start, z_end);
	x_start *= data->zoom;
	x_end *= data->zoom;
	y_start *= data->zoom;
	y_end *= data->zoom;
	x_start += data->position_x + 200;
	x_end += data->position_x + 200;
	y_start += data->position_y - 75;
	y_end += data->position_y - 75;
	x_start = (x_start - y_start) * 0.5;
	y_start = (x_start + y_start) * 0.6 - (z_start * data->depth);
	x_end = (x_end - y_end) * 0.5;
	y_end = (x_end + y_end) * 0.6 - (z_end * data->depth);
	x_way = x_end - x_start;
	y_way = y_end - y_start;
	x_way /= max(mod(x_end - x_start), mod(y_end - y_start));
	y_way /= max(mod(x_end - x_start), mod(y_end - y_start));
	draw(data, x_start, y_start, x_end, y_end, x_way, y_way);
}

void	illustration(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	menu(data);
	while (data->height > y)
	{
		x = 0;
		while (data->width > x)
		{
			if (data->width - 1 > x)
				algorithm(data, x, y, x + 1, y);
			if (data->height - 1 > y)
				algorithm(data, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}
