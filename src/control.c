/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:56:58 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/09 19:35:33 by yugurlu          ###   ########.fr       */
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
			data->depth += 0.1;
		else if (key == 19)
			data->depth -= 0.1;
		else if (key == 53)
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
