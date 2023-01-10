/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:20:28 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/10 17:53:29 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_image(t_fdf *data)
{
	if (data->mlx_img->img)
		mlx_destroy_image(data->mlx, data->mlx_img->img);
	data->mlx_img->img = mlx_new_image(data->mlx, 4096, 2160);
	data->mlx_img->addr = mlx_get_data_addr(data->mlx_img->img,
			&data->mlx_img->bits_per_pixel,
			&data->mlx_img->line_length,
			&data->mlx_img->endian);
}
