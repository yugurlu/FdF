/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 07:17:39 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/10 17:56:53 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	m(float number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

int	mx(float number, float number2)
{
	if (number > number2)
		return (number);
	return ((int)number2);
}

void	free_all(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data->mlx_img);
	free(data->l);
	free(data);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

bool	ft_error(int error, char *map)
{
	if (error == 1)
	{
		ft_printf("%s\n", "please choose a map");
		exit(1);
	}
	else if (error == 2 && open(map, O_RDONLY) != 3)
	{
		ft_printf("%s\n", "wrong map name!");
		exit(1);
	}
	else
		return (true);
}
