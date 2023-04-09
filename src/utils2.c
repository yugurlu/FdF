/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:20:28 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/06 03:25:09 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	check_map(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] == 'f' && map[i - 2] == 'd' && map[i - 3] == 'f' && map[i
			- 4] == '.' && open(map, O_RDONLY) == 3)
		return (true);
	return (false);
}

int	hex_to_decimal(char *hex)
{
	char	**arr;
	int		decimal;
	int		i;
	int		len;
	int		val;

	decimal = 0;
	i = 0;
	arr = ft_split(hex, '\n');
	len = ft_strlen(arr[0]);
	while (i < len)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			val = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			val = hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			val = hex[i] - 'A' + 10;
		else
			val = 0;
		decimal = decimal * 16 + val;
		i++;
	}
	free_split(arr);
	return (decimal);
}

void	fill_array(t_fdf *data, char **arr)
{
	static int	i;
	int			j;
	int			l;

	j = 0;
	while (data->width > j)
	{
		l = 0;
		data->colour_matrix[i][j] = malloc(sizeof(char) * ft_strlen(arr[j]));
		while (arr[j][l])
		{
			data->colour_matrix[i][j][l] = arr[j][l];
			l++;
		}
		data->colour_matrix[i][j][l] = '\0';
		j++;
	}
	data->colour_matrix[i][j] = NULL;
	i++;
}

void	mlx_image(t_fdf *data, int x, int y)
{
	if (x || y)
		mlx_destroy_image(data->mlx, data->mlx_img->img);
	if (x + y == 0)
		ft_printf("%sDone!", "\e[92m");
	data->mlx_img->img = mlx_new_image(data->mlx, 4096, 2160);
	data->mlx_img->addr = mlx_get_data_addr(data->mlx_img->img,
			&data->mlx_img->bits_per_pixel,
			&data->mlx_img->line_length,
			&data->mlx_img->endian);
	illustration(data);
}
