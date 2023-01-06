/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 07:17:39 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/06 17:56:59 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	m(float number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

float	mx(float number, float number2)
{
	if (number > number2)
		return (number);
	return (number2);
}

void	free_all(t_fdf *data)
{
	int i;

	i = 0;
	(void)data;
		/*while (i < data->say)
	{
		printf("a\n");
		//free(data->z_matrix[i++]);
	}
	free(data->z_matrix);*/
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	menu(t_fdf *data)
{
	char	*menu;

	menu = "move: use arrow keys";
	mlx_string_put(data->mlx, data->mlx_window, 10, 10, 0xffffff, menu);
	menu = "zoom: use mouse scrool";
	mlx_string_put(data->mlx, data->mlx_window, 10, 35, 0xffffff, menu);
	menu = "depth: use buttons '1' or '2'";
	mlx_string_put(data->mlx, data->mlx_window, 10, 60, 0xffffff, menu);
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
