/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:20:28 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/07 17:18:25 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_height(t_fdf *data)
{
	int		fd;
	char	*line;

	data->height = 0;
	fd = open(data->map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	map_width(t_fdf *data)
{
	int		fd;
	char	*line;
	char	**clear_line;

	data->width = 0;
	fd = open(data->map, O_RDONLY);
	line = get_next_line(fd);
	clear_line = ft_split(line, ' ');
	while (clear_line[data->width])
		data->width++;
	data->map_size = data->width * data->height;
	free(line);
	free_split(clear_line);
	close(fd);
}

void	complate_matrix(t_fdf *data)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**clear_line;

	i = 0;
	fd = open(data->map, O_RDONLY);
	data->z_matrix = malloc(sizeof(int) * data->height);
	while (data->height > i)
	{
		j = 0;
		line = get_next_line(fd);
		clear_line = ft_split(line, ' ');
		data->z_matrix[i] = malloc(sizeof(int) * data->width);
		while (data->width > j)
		{

			data->z_matrix[i][j] = ft_atoi(clear_line[j]);
			printf("%3d", ft_atoi(clear_line[j]));
			j++;
		}
		printf("\n");

		i++;
		free(line);
		free_split(clear_line);
	}
		printf("\n");
		printf("\n");
		printf("\n");


	i = 0;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
			printf("%3d", data->z_matrix[i][j++]);
		printf("\n");
		i++;
	}
	system("leaks a.out");
	getchar();
	close(fd);
}

void	read_map(t_fdf *data, char *map)
{
	data->map = map;
	map_height(data);
	map_width(data);
	complate_matrix(data);
}
