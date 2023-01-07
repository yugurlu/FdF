/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 07:17:39 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/07 14:41:23 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	m(float number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

int	mx(float number, float number2)
{
	if (number > number2)
		return (number);
	return ((int)number2);
}

void	free_all(t_fdf *data)
{
	int i = 0;

	while (i < data->height)
		free(data->z_matrix[i++]);
	free(data->z_matrix);
}

void	free_split(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	menu(t_fdf *data)
{
	char	*menu;
	menu = malloc(100);

	menu = "move: use arrow keys";
	mlx_string_put(data->mlx, data->mlx_window, 10, 10, 0xffffff, menu);
	menu = "zoom: use mouse scrool";
	mlx_string_put(data->mlx, data->mlx_window, 10, 35, 0xffffff, menu);
	menu = "depth: use buttons '1' or '2'";
	mlx_string_put(data->mlx, data->mlx_window, 10, 60, 0xffffff, menu);
	mlx_string_put(data->mlx, data->mlx_window, 10, 95, 0x7FFF00, ft_itoa(data->pixel_count));
}

void	colour(t_fdf *data, float z_start, float z_end)
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
