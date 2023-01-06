/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illustration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:38:32 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/06 16:11:17 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *data, float x_way, float y_way)
{
	while ((int)(data->l->x_e - data->l->x_s) || (int)(data->l->y_e
			- data->l->y_s))
	{
		mlx_pixel_put(data->mlx, data->mlx_window, data->l->x_s, data->l->y_s,
			data->colour);
		data->l->x_s += x_way;
		data->l->y_s += y_way;
	}
}

void	algorithm(t_fdf *data)
{
	float	x_way;
	float	y_way;
	float	z_s;
	float	z_e;

	z_s = data->z_matrix[(int)data->l->l_y_s][(int)data->l->l_x_s];
	z_e = data->z_matrix[(int)data->l->l_y_e][(int)data->l->l_x_e];
	colour(data, z_s, z_e);
	data->l->x_s = data->l->l_x_s * data->zoom;
	data->l->x_e = data->l->l_x_e * data->zoom;
	data->l->y_s = data->l->l_y_s * data->zoom;
	data->l->y_e = data->l->l_y_e * data->zoom;
	data->l->x_s += data->position_x + 200;
	data->l->x_e += data->position_x + 200;
	data->l->y_s += data->position_y - 75;
	data->l->y_e += data->position_y - 75;
	data->l->x_s = (data->l->x_s - data->l->y_s) * 0.5;
	data->l->y_s = (data->l->x_s + data->l->y_s) * 0.6 - (z_s * data->depth);
	data->l->x_e = (data->l->x_e - data->l->y_e) * 0.5;
	data->l->y_e = (data->l->x_e + data->l->y_e) * 0.6 - (z_e * data->depth);
	x_way = data->l->x_e - data->l->x_s;
	y_way = data->l->y_e - data->l->y_s;
	x_way /= mx(m(data->l->x_e - data->l->x_s), m(data->l->y_e - data->l->y_s));
	y_way /= mx(m(data->l->x_e - data->l->x_s), m(data->l->y_e - data->l->y_s));
	draw(data, x_way, y_way);
}

void	illustration(t_fdf *data)
{
	data->l->l_y_s = 0;
	menu(data);
	while (data->height > data->l->l_y_s)
	{
		data->l->l_x_s = 0;
		while (data->width > data->l->l_x_s)
		{
			if (data->width - 1 > data->l->l_x_s)
			{
				data->l->l_x_e = data->l->l_x_s + 1;
				algorithm(data);
				data->l->l_x_e = data->l->l_x_s;
			}
			if (data->height - 1 > data->l->l_y_s)
			{
				data->l->l_y_e = data->l->l_y_s + 1;
				algorithm(data);
				data->l->l_y_e = data->l->l_y_s;
			}
			data->l->l_x_s++;
		}
		data->l->l_y_s++;
	}
}
