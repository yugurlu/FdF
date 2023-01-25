/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illustration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:38:32 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/24 12:55:09 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx_img->addr + (y * data->mlx_img->line_length + x
			* (data->mlx_img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_fdf *data, float x_way, float y_way)
{
	if ((0 <= data->l->x_s && data->l->x_s <= data->window_x)
		&& (0 <= data->l->y_s && data->l->y_s <= data->window_y))
	{
		while (((int)(data->l->x_e - data->l->x_s) || (int)(data->l->y_e
			- data->l->y_s)) && ((0 <= data->l->x_s
					&& data->l->x_s <= data->window_x) && (0 <= data->l->y_s
					&& data->l->y_s <= data->window_y)))
		{
			my_mlx_pixel_put(data, data->l->x_s, data->l->y_s, data->colour);
			data->l->x_s += x_way;
			data->l->y_s += y_way;
		}
	}
}

void	position_zoom(t_fdf *data, float x_e, float y_e)
{
	data->l->x_s = data->l->l_x_s * data->zoom;
	data->l->x_e = x_e * data->zoom;
	data->l->y_s = data->l->l_y_s * data->zoom;
	data->l->y_e = y_e * data->zoom;
	data->l->x_s += data->position_x + 200;
	data->l->x_e += data->position_x + 200;
	data->l->y_s += data->position_y - 75;
	data->l->y_e += data->position_y - 75;
}

void	dda(t_fdf *data, float x_e, float y_e)
{
	float	x_way;
	float	y_way;

	data->l->z_s = data->z_matrix[(int)data->l->l_y_s][(int)data->l->l_x_s];
	data->l->z_e = data->z_matrix[(int)y_e][(int)x_e];
	colour(data, x_e, y_e);
	position_zoom(data, x_e, y_e);
	if (data->projection)
	{
		data->l->x_s = (data->l->x_s - data->l->y_s) * 0.5;
		data->l->y_s = (data->l->x_s + data->l->y_s) * 0.5 - (data->l->z_s
				* data->depth);
		data->l->x_e = (data->l->x_e - data->l->y_e) * 0.5;
		data->l->y_e = (data->l->x_e + data->l->y_e) * 0.5 - (data->l->z_e
				* data->depth);
	}
	x_way = data->l->x_e - data->l->x_s;
	y_way = data->l->y_e - data->l->y_s;
	x_way /= mx(m(data->l->x_e - data->l->x_s), m(data->l->y_e - data->l->y_s));
	y_way /= mx(m(data->l->x_e - data->l->x_s), m(data->l->y_e - data->l->y_s));
	draw(data, x_way, y_way);
}

void	illustration(t_fdf *data)
{
	float	x;
	float	y;

	y = 0;
	data->l->l_y_s = 0;
	while (data->height > data->l->l_y_s)
	{
		data->l->l_x_s = 0;
		x = 0;
		while (data->width > data->l->l_x_s)
		{
			if (data->width - 1 > data->l->l_x_s)
				dda(data, x + 1, y);
			if (data->height - 1 > data->l->l_y_s)
				dda(data, x, y + 1);
			data->l->l_x_s++;
			x++;
		}
		data->l->l_y_s++;
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->mlx_img->img, 0,
		0);
	menu(data);
}
