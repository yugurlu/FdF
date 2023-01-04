/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:31:25 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/04 20:45:26 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MAX(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? (a * -1) : a)

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct
{
	int		**z_matrix;
	char	**for_colour;
	char	*map;
	void	*mlx;
	void	*mlx_window;
	int		height;
	int		width;
	int		map_size;
	int 	position_x;
	int 	position_y;
	int		zoom;
	int		depth;
	int		colour;
}			fdf;

fdf *g;

void		read_map(fdf *data, char *map);
void		bresenham(fdf *data, float x_start, float y_start, float x_end,
				float y_end);
void		illustration(fdf *data);
int		key_target(int key, fdf *data);
//int		mouse_target(int key, int *zoom);
int		mouse_target(int key, void *x);

#endif
