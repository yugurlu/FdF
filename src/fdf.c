/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:09:51 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/25 19:48:20 by yugurlu          ###   ########.fr       */
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
		data->depth = zoom - 15;
	if (data->map_size > 10000)
		data->depth = 0.2;
	data->projection = 1;
}

void	set_default(t_fdf *data, char **av)
{
	read_map(data, av[1]);
	if (data->map_size <= 500)
		program_settings(data, 920, 680, 25);
	else if (data->map_size <= 3000)
		program_settings(data, 1280, 720, 20);
	else if (data->map_size <= 5000)
		program_settings(data, 1366, 768, 20);
	else if (data->map_size <= 10000)
		program_settings(data, 1600, 900, 10);
	else
		program_settings(data, 1920, 1080, 5);
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
		data->mlx_img->img = mlx_new_image(data->mlx, 4096, 2160);
	data->mlx_img->addr = mlx_get_data_addr(data->mlx_img->img,
			&data->mlx_img->bits_per_pixel,
			&data->mlx_img->line_length,
			&data->mlx_img->endian);
	illustration(data);
		mlx_mouse_hook(data->mlx_window, mouse_target, data);
		mlx_hook(data->mlx_window, 2, 1L << 0, key_target, data);
		mlx_hook(data->mlx_window, 17, 0, closee, data);
		mlx_loop(data->mlx);
	}
	else
		ft_error(1, ac, "none");
}
