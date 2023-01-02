/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:09:51 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/02 13:43:50 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	fdf	*data;

	(void)ac;
	data = malloc(sizeof(fdf));
	data->zoom = 20;
	read_map(data, av[1]);
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, 1920, 1080, "FDF");
	illustration(data);
	mlx_mouse_hook(data->mlx_window, mouse_target, data);
	mlx_key_hook(data->mlx_window, key_target, data);
	mlx_loop(data->mlx);
}
