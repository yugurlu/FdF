/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:31:25 by yugurlu           #+#    #+#             */
/*   Updated: 2022/12/22 18:10:04 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./get_next_line/get_next_line.h"
# include "./minilibx_macos/mlx.h"
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
	void	*mlx;
	void	*mlx_window;
	t_data	*pxl;
}			fdf;

#endif
