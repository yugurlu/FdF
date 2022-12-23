/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:09:51 by yugurlu           #+#    #+#             */
/*   Updated: 2022/12/23 16:47:25 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pxl->addr + (y * data->pxl->line_length + x
			* (data->pxl->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **av)
{
	fdf	*data;
	int	i;
	int	j;

	(void)ac;
	data = malloc(sizeof(fdf));
	data->pxl = malloc(sizeof(t_data));
	read_map(data, av[1]);
	i = 0;
	while (data->height > i)
	{
		j = 0;
		while (data->width > j)
			printf("%3d", data->z_matrix[i][j++]);
		printf("\n");
		i++;
	}
/*
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, 1920, 1080, "FDF");
	data->pxl->img = mlx_new_image(data->mlx, 1920, 1080);
	data->pxl->addr = mlx_get_data_addr(data->pxl->img,
			&data->pxl->bits_per_pixel, &data->pxl->line_length,
			&data->pxl->endian);
	ft_mlx_pixel_put(data, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->pxl->img, 0, 0);
	mlx_loop(data->mlx);*/
}
