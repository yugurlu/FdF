/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illustration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:38:32 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/05 17:39:55 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(fdf *data, float x_start, float y_start, float x_end, float y_end)
{
	while ((int)(x_end - x_start) || (int)(y_end - y_start))
	{
		mlx_pixel_put(data->mlx, data->mlx_window, x_start, y_start,
				data->colour);
		x_start += data->x_way;
		y_start += data->y_way;
	}
}

void		way(fdf *data, float x_start, float y_start, float x_end, float y_end)
{
	data->x_way = x_end - x_start;
	data->y_way = y_end - y_start;
	if(data->x_way < 0)
		data->x_way *= -1;
	if(data->y_way < 0)
		data->y_way *= -1;
	if(data->x_way > data->y_way)
	{
		float max = data->x_way;
		data->x_way /= max;
		data->y_way /= max;
		printf("\nX = %f\n", data->x_way);
		printf("\nY = %f\n", data->y_way);
	}
	else
	{
		float max = data->y_way;
		data->x_way /= max;
		data->y_way /= max;
	printf("\nX = %f\n", data->x_way);
	printf("\nY = %f\n", data->y_way);

	}
}

	/*x_way = x_end - x_start;
	y_way = y_end - y_start;
	max = MAX(MOD(x_way), MOD(y_way));
	x_way /= max;
	y_way /= max;*/

void	bresenham(fdf *data, float x_start, float y_start, float x_end,
		float y_end)
{
	//float x_way;
	//float y_way;
	//float max;
	float	z_start;
	float	z_end;

	//Z START - Z END
	z_start = data->z_matrix[(int)y_start][(int)x_start];
	z_end = data->z_matrix[(int)y_end][(int)x_end];
	//colour
	colour(data, z_start, z_end);
	//zoom
	x_start *= data->zoom;
	x_end *= data->zoom;
	y_start *= data->zoom;
	y_end *= data->zoom;
	//position
	x_start += data->position_x + 75;
	x_end += data->position_x + 75;
	y_start += data->position_y - 45;
	y_end += data->position_y - 45;
	//3D
	x_start = (x_start - y_start) * 0.5;
	y_start = (x_start + y_start) * 0.6 - (z_start * data->depth);
	x_end = (x_end - y_end) * 0.5;
	y_end = (x_end + y_end) * 0.6 - (z_end * data->depth);
	/*x_way = x_end - x_start;
	y_way = y_end - y_start;

	max = MAX(MOD(x_way), MOD(y_way));

	x_way /= max;
	y_way /= max;
	printf("\nx = %f\n", x_way);
	printf("\ny = %f\n", y_way);*/
	way(data, x_start, y_start, x_end, y_end);
	draw(data, x_start, y_start, x_end, y_end);
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
			if (data->width - 1 > x)
				bresenham(data, x, y, x + 1, y);
			if (data->height - 1 > y)
				bresenham(data, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}
