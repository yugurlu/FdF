/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:09:51 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/06 18:12:02 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

void	set_default(t_fdf *data, char **av)
{
	read_map(data, av[1]);
	if (data->map_size <= 1500)
		data->zoom = 25;
	else if (data->map_size <= 5000)
		data->zoom = 15;
	else
		data->zoom = 5;
	data->depth = 10;
	data->flag = 0;
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac == 2)
	{
		data = malloc(sizeof(t_fdf));
		data->l = malloc(sizeof(t_line));
		set_default(data, av);
		data->mlx = mlx_init();
		data->mlx_window = mlx_new_window(data->mlx, 1600, 900, "FDF");
		illustration(data);
		mlx_mouse_hook(data->mlx_window, mouse_target, data);
		mlx_hook(data->mlx_window, 2, 1L << 0, key_target, data);
		mlx_loop(data->mlx);
		//free_all(data);
	}
	system("leaks a.out");
}
