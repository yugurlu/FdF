/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 07:17:39 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/26 18:12:48 by yugurlu          ###   ########.fr       */
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
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
		free(data->z_matrix[i++]);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
			free(data->colour_matrix[i][j++]);
		free(data->colour_matrix[i]);
		i++;
	}
	free(data->colour_matrix);
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

bool	ft_error(int error, int ac, char *map)
{
	if (error == 1 && ac == 1)
	{
		ft_printf("%sERROR: Please choose a map!\n", "\e[31m");
		exit(1);
	}
	else if (error == 2 && check_map(map) == false)
	{
		ft_printf("%sERROR: Wrong map name!\n", "\e[31m");
		exit(1);
	}
	else if (error == 1 && ac != 2)
	{
		ft_printf("%sERROR: Wrong argument number!\n", "\e[31m");
		exit(1);
	}
	else
		return (true);
}
