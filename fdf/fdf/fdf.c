/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:09:51 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/04 20:46:17 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

void	set_default(fdf *data, char **av)
{
	read_map(data, av[1]);
	if (data->map_size <= 5000)
		data->zoom = 20;
	else
		data->zoom = 5;
	data->depth = 10;
}


int	main(int ac, char **av)
{
	fdf	*data;
	fdf *buff;

	if (ac == 2)
	{
		data = calloc(sizeof(fdf), 1000);
		buff = calloc(sizeof(fdf), 1000);
		set_default(data, av);
		data->mlx = mlx_init();
		data->mlx_window = mlx_new_window(data->mlx, 600, 600, "FDF");
		illustration(data);
		g = data;
		buff = data;
		mlx_mouse_hook(data->mlx_window, mouse_target, data);
		mlx_hook(data->mlx_window, 2, 1L << 0, key_target, buff);
		mlx_loop(data->mlx);
	}
}
