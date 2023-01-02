/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:20:28 by yugurlu           #+#    #+#             */
/*   Updated: 2022/12/30 12:11:18 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_height(fdf *data)
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

void	map_width(fdf *data)
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
	free(line);
	close(fd);
}

void	complate_matrix(fdf *data)
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
			j++;
		}
		i++;
		free(line);
	}
	close(fd);
}

void	read_map(fdf *data, char *map)
{
	data->map = map;
	map_height(data);
	map_width(data);
	complate_matrix(data);
}
