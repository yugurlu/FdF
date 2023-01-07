/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:56:58 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/07 13:23:54 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_target(int key, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	if (key == 4 || key == 5)
	{
		if (key == 4)
			data->zoom += 4;
		else if (key == 5)
			data->zoom -= 4;
		mlx_clear_window(data->mlx, data->mlx_window);
		illustration(data);
	}
	return (0);
}

int	key_target(int key, t_fdf *data)
{
	if ((126 >= key && key >= 123) || key == 53 || key == 19 || key == 18)
	{
		if (key == 124)
			data->position_x += 50;
		else if (key == 123)
			data->position_x -= 50;
		else if (key == 126)
			data->position_y -= 50;
		else if (key == 125)
			data->position_y += 50;
		else if (key == 18)
			data->depth++;
		else if (key == 19)
			data->depth--;
		else if (key == 53)
		{
			mlx_destroy_window(data->mlx, data->mlx_window);
			exit(1);
		}
		mlx_clear_window(data->mlx, data->mlx_window);
		illustration(data);
	}
	return (0);
}
