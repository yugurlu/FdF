/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:31:25 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/23 14:36:29 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_line
{
	float	x_s;
	float	y_s;
	float	x_e;
	float	y_e;
	float	z_s;
	float	z_e;
	float	l_x_s;
	float	l_y_s;
	float	l_x_e;
	float	l_y_e;
}			t_line;

typedef struct s_fdf
{
	char	***colour_matrix;
	int		**z_matrix;
	char	*map;
	void	*mlx;
	void	*mlx_window;
	int		window_x;
	int		window_y;
	int		height;
	int		width;
	int		map_size;
	int		position_x;
	int		position_y;
	int		zoom;
	float	depth;
	int		colour;
	t_line	*l;
	t_data	*mlx_img;
}			t_fdf;

float		m(float number);
void		menu(t_fdf *data);
int			closee(t_fdf *data);
bool		check_map(char *map);
void		free_all(t_fdf *data);
void		free_split(char **arr);
void		mlx_image(t_fdf *data);
void		illustration(t_fdf *data);
int			hex_to_decimal(char *hex);
void		allocate_memory(t_fdf *data);
int			mx(float number, float number2);
int			key_target(int key, t_fdf *data);
void		read_map(t_fdf *data, char *map);
void		fill_array(t_fdf *data, char **arr);
bool		ft_error(int error, int ac, char *map);
void		algorithm(t_fdf *data, float x_e, float y_e);
void		colour(t_fdf *data, float z_start, float z_end);
int			mouse_target(int key, int x, int y, t_fdf *data);
void		def_colour(t_fdf *data, float z_start, float z_end);

#endif
