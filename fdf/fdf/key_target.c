/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:56:58 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/04 20:45:16 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_target(int key, void *x)
{
	printf("data : %p\n", x);
	printf("g : %d\n",g->zoom);
	//printf("data adresss yusufum : %p\n", &data);
	printf("key : %d\n",key);
	/*if (key == 4)
		data->zoom += 1;
	if (key == 5)
		data->zoom -= 1;*/
	/*if (key == 4)
		data->zoom += 1;
	else if (key == 5)
		data->zoom -= 1;*/
	//mlx_clear_window(data->mlx, data->mlx_window);
	//illustration(data);
	return (0);
}

int	key_target(int key, fdf *data)
{
	printf("data zoooom : %p\n",data);
	printf("%d\n", key);
	if (key == 124)
		data->position_x += 2;
	else if (key == 123)
		data->position_x -= 2;
	else if (key == 126)
		data->position_y -= 2;
	else if (key == 125)
		data->position_y += 2;
	else if (key == 18)
		data->depth++;
	else if (key == 19)
		data->depth--;
	else if (key == 53) {

		mlx_destroy_window(data->mlx, data->mlx_window);
		exit(1);
	}
	mlx_clear_window(data->mlx, data->mlx_window);
	illustration(data);
	return (0);
}
