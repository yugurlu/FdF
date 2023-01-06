/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:31:25 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/06 18:10:17 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_line
{
	float	x_s;
	float	y_s;
	float	x_e;
	float	y_e;
	float	l_x_s;
	float	l_y_s;
	float	l_x_e;
	float	l_y_e;
}			t_line;

typedef struct s_fdf
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
	int		colour;
	int		flag;
	int		say; // degistir
	t_line	*l;
}			t_fdf;

float		m(float number);
float		mx(float number, float number2);
void		menu(t_fdf *data);
void		free_all(t_fdf *data);
void		free_split(char **split);
void		read_map(t_fdf *data, char *map);
void		algorithm(t_fdf *data);
void		illustration(t_fdf *data);
int			key_target(int key, t_fdf *data);
int			mouse_target(int key, int x, int y, t_fdf *data);
void		colour(t_fdf *data, float z_start, float z_end);

#endif
