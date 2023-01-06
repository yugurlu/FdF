/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:31:25 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/06 08:08:52 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibX/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct
{
	int		**z_matrix;
	char	*map;
	void	*mlx;
	void	*mlx_window;
	int		height;
	int		width;
	int		map_size;
	int		position_x;
	int		position_y;
	int		zoom;
	int		depth;
	int		for_3d;
	int		colour;
}			fdf;

float		mod(float number);
float		max(float number, float number2);
void		menu(fdf *data);
void		read_map(fdf *data, char *map);
void		algorithm(fdf *data, float x_start, float y_start, float x_end,
				float y_end);
void		illustration(fdf *data);
int			key_target(int key, fdf *data);
int			mouse_target(int key, int x, int y, fdf *data);
void		colour(fdf *data, float z_start, float z_end);

#endif
