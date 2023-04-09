/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:09:51 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/09 19:39:24 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

void	program_settings(t_fdf *data, int window_x, int window_y, float zoom)
{
	data->window_x = window_x;
	data->window_y = window_y;
	data->zoom = zoom;
	if (data->map_size <= 500)
		data->depth = 2.5;
	else if (data->map_size <= 3000)
		data->depth = 4;
	else if (data->map_size <= 5000)
		data->depth = 7;
	else if (data->map_size <= 10000)
		data->depth = 6;
	else
		data->depth = 0.2;
	data->projection = 1;
}

void	set_default(t_fdf *data, char **av)
{
	read_map(data, av[1]);
	if (data->map_size <= 500)
		program_settings(data, 920, 680, 20);
	else if (data->map_size <= 3000)
		program_settings(data, 1280, 720, 15);
	else if (data->map_size <= 5000)
		program_settings(data, 1366, 768, 15);
	else if (data->map_size <= 10000)
		program_settings(data, 1600, 900, 12);
	else
		program_settings(data, 1920, 1080, 5);
	ft_printf("Creating Illustration...\n");
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac == 2 && ft_error(2, ac, av[1]))
	{
		data = malloc(sizeof(t_fdf));
		data->l = malloc(sizeof(t_line));
		data->mlx_img = malloc(sizeof(t_data));
		set_default(data, av);
		data->mlx = mlx_init();
		data->mlx_window = mlx_new_window(data->mlx, data->window_x,
				data->window_y, "FDF");
		mlx_image(data, 0, 0);
		mlx_mouse_hook(data->mlx_window, mouse_target, data);
		mlx_hook(data->mlx_window, 2, 1L << 0, key_target, data);
		mlx_hook(data->mlx_window, 17, 0, closee, data);
		mlx_loop(data->mlx);
	}
	else
		ft_error(1, ac, "none");
}
