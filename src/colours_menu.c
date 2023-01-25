/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:58:04 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/24 09:20:59 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_fdf *data)
{
	mlx_string_put(data->mlx, data->mlx_window, 10, 10, 0xffffff,
		"move: use arrow keys");
	mlx_string_put(data->mlx, data->mlx_window, 10, 35, 0xffffff,
		"zoom: use mouse scrool");
	mlx_string_put(data->mlx, data->mlx_window, 10, 60, 0xffffff,
		"projection: use mouse click");
	mlx_string_put(data->mlx, data->mlx_window, 10, 85, 0xffffff,
		"depth: use buttons '1' or '2'");
}

void	colour(t_fdf *data, float x_e, float y_e)
{
	char	**colour;

	if (!ft_strchr(data->colour_matrix[(int)data->l->l_y_s]
			[(int)data->l->l_x_s], ','))
	{
		colour = ft_split(data->colour_matrix[(int)data->l->l_y_s]
			[(int)data->l->l_x_s], ',');
		data->colour = hex_to_decimal(colour[1]);
		free_split(colour);
	}
	else if (!ft_strchr(data->colour_matrix[(int)y_e]
			[(int)x_e], ','))
	{
		colour = ft_split(data->colour_matrix[(int)y_e]
			[(int)x_e], ',');
		data->colour = hex_to_decimal(colour[1]);
		free_split(colour);
	}
	else
		def_colour(data, data->l->z_s, data->l->z_e);
}

void	def_colour(t_fdf *data, float z_start, float z_end)
{
	if ((z_start <= 2 && z_start > 0) || (z_end <= 2 && z_end > 0)
		|| (z_start >= -2 && z_start < 0) || (z_end >= -2 && z_end < 0))
		data->colour = 0x0000ff;
	else if ((z_start <= 4 && z_start > 2) || (z_end <= 4 && z_end > 2)
		|| (z_start >= -4 && z_start < -2) || (z_end >= -4 && z_end < -2))
		data->colour = 0x0033ff;
	else if ((z_start <= 6 && z_start > 4) || (z_end <= 6 && z_end > 4)
		|| (z_start >= -6 && z_start < -4) || (z_end >= -6 && z_end < -4))
		data->colour = 0x00ccff;
	else if ((z_start <= 8 && z_start > 6) || (z_end <= 8 && z_end > 6)
		|| (z_start >= -8 && z_start < -6) || (z_end >= -8 && z_end < -6))
		data->colour = 0x00ffff;
	else if ((z_start <= 10 && z_start > 8) || (z_end <= 10 && z_end > 8)
		|| (z_start >= -10 && z_start < -8) || (z_end >= -10 && z_end < -8))
		data->colour = 0x00ffcc;
	else if ((z_start <= 12 && z_start > 10) || (z_end <= 12 && z_end > 10)
		|| (z_start >= -12 && z_start < -10) || (z_end >= -10 && z_end < -8))
		data->colour = 0x00ff99;
	else if ((z_start > 12) || (z_end > 12) || (z_start < -12) || (z_end < -12))
		data->colour = 0x99ff00;
	else
		data->colour = 0x000099;
}
