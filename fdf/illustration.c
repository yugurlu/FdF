/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illustration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:38:32 by yugurlu           #+#    #+#             */
/*   Updated: 2022/12/24 17:17:40 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	bresenham(fdf *data, float x_start, float y_start, float x_end,
		float y_end)
{
	int		colour;
	int		max;
	float	x_way;
	float	y_way;

	(void)data;
	x_way = x_end - x_start;
	y_way = y_end - y_start;
	max = MAX(MOD(x_way), MOD(y_way));
	x_way /= max;
	y_way /= max;
	colour = 0x6a5acd;
	while ((int)(x_end - x_start) || (int)(y_end - y_start))
	{
		mlx_pixel_put(data->mlx, data->mlx_window, x_start, y_start, colour);
		x_start += x_way;
		y_start += y_way;
		colour += 50;
	}
}

void	illustration(fdf *data)
{
	int	height;
	int	width;
	int	x;
	int	y;

	x = 100;
	y = 100;
	height = 0;
	width = 0;
	(void)width;
	while (data->height > height)
	{
		bresenham(data, x, y, x + 540, y);
		height++;
		y += 30;
	}
	y = 100;
	while (data->width > width)
	{
		bresenham(data, x, y, x, y + 300);
		width++;
		x += 30;
	}
}
