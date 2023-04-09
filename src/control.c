/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:56:58 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/09 18:25:50 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	closee(t_fdf *data)
{
	free_all(data);
	exit(1);
}

int	mouse_target(int key, int x, int y, t_fdf *data)
{
	static int	temp;
	static int	flag;

	if (key == 1 || key == 4 || key == 5)
	{
		if (key == 4)
			data->zoom += 1;
		else if (key == 5)
			data->zoom -= 1;
		else if (key == 1 && flag == 0)
		{
			flag = 1;
			temp = data->zoom;
			data->zoom = temp - 1;
			data->projection = 0;
		}
		else if (key == 1 && flag == 1)
		{
			flag = 0;
			data->zoom = temp;
			data->projection = 1;
		}
		mlx_image(data, x, y);
	}
	return (0);
}

int	key_target(int key, t_fdf *data)
{
	if ((65364 >= key && key >= 65361) || key == 65307 || key == 50 || key == 49)
	{
		if (key == 65361)
			data->position_x += 50;
		else if (key == 65363)
			data->position_x -= 50;
		else if (key == 65364)
			data->position_y -= 50;
		else if (key == 65362)
			data->position_y += 50;
		else if (key == 49)
			data->depth += 0.1;
		else if (key == 50)
			data->depth -= 0.1;
		else if (key == 65307)
		{
			mlx_destroy_image(data->mlx, data->mlx_img->img);
			mlx_destroy_window(data->mlx, data->mlx_window);
			free_all(data);
			exit(1);
		}
		mlx_image(data, 1, 1);
	}
	return (0);
}
