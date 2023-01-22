/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:28:24 by yugurlu           #+#    #+#             */
/*   Updated: 2022/10/28 15:36:31 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *a)
{
	int	i;

	i = 0;
	if (!a)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (a[i])
	{
		write(1, &a[i], 1);
		i++;
	}
	return (i);
}
