/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:34:58 by yugurlu           #+#    #+#             */
/*   Updated: 2023/01/05 12:35:11 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colour(fdf *data, float z_start, float z_end)
{
	if ((z_start <= 2 && z_start > 0) || (z_end <= 2 && z_end > 0)
		|| (z_start >= -2 && z_start < 0) || (z_end >= -2 && z_end < 0))
		data->colour = 0x0000ff;
	else if ((z_start <= 4 && z_start > 2) || (z_end <= 4 && z_end > 2)
			|| (z_start >= -4 && z_start < -2) || (z_end >= -4 && z_end < -2))
		data->colour = 0x0033ff;
	else if ((z_start <= 6 && z_start > 4) || (z_end <= 6 && z_end > 4)
			|| (z_start >= -6 && z_start < -4) || (z_end >= -6 && z_end < -4))
		data->colour = 0x00ccff;
	else if ((z_start <= 8 && z_start > 6) || (z_end <= 8 && z_end > 6)
			|| (z_start >= -8 && z_start < -6) || (z_end >= -8 && z_end < -6))
		data->colour = 0x00ffff;
	else if ((z_start <= 10 && z_start > 8) || (z_end <= 10 && z_end > 8)
			|| (z_start >= -10 && z_start < -8) || (z_end >= -10 && z_end < -8))
		data->colour = 0x00ffcc;
	else if ((z_start <= 12 && z_start > 10) || (z_end <= 12 && z_end > 10)
			|| (z_start >= -12 && z_start < -10) || (z_end >= -10 && z_end <
				-8))
		data->colour = 0x00ff99;
	else if ((z_start > 12) || (z_end > 12) || (z_start < -12) || (z_end < -12))
		data->colour = 0x99ff00;
	else
		data->colour = 0x000099;
}
