/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:31:25 by yugurlu           #+#    #+#             */
/*   Updated: 2022/12/25 15:03:05 by yugurlu          ###   ########.fr       */
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
# include <stdio.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		*z_matrix;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct
{
	int		**z_matrix;
	char	*map;
	void	*mlx;
	void	*mlx_window;
	int		height;
	int		width;
	int 	zoom;
	int 	colour;
	t_data	*pxl;
}			fdf;

void		read_map(fdf *data, char *map);
void		bresenham(fdf *data, float x_start, float y_start, float x_end,
				float y_end);
void	illustration(fdf *data);

#endif
