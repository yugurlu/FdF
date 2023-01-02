/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:56:58 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/02 13:45:22 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_target(int key, fdf *data)
{
	if (key == 4)
		data->zoom += 2;
	else if (key == 5)
		data->zoom -= 2;
	/*mlx_clear_window(data->mlx, data->mlx_window);
	illustration(data);*/
	return (0);
}

int	key_target(int key, fdf *data)
{
	if (key == 124)
		data->position_x += 5;
	else if (key == 123)
		data->position_x -= 5;
	else if (key == 126)
		data->position_y -= 5;
	else if (key == 125)
		data->position_y += 5;
	else if (key == 53)
		mlx_destroy_window(data->mlx, data->mlx_window);
	mlx_clear_window(data->mlx, data->mlx_window);
	illustration(data);
	return (0);
}
