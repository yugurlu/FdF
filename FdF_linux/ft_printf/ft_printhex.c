/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:16:57 by yugurlu           #+#    #+#             */
/*   Updated: 2022/10/28 13:17:36 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

void	ft_print_hex(unsigned long num, char format)
{
	if (num >= 16)
	{
		ft_print_hex(num / 16, format);
		ft_print_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x' || format == 'p')
				ft_putchar(num - 10 + 'a');
			else
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	ft_print_ptr(unsigned long num, char format)
{
	int	count;

	count = 0;
	count += ft_printstr("0x");
	if (num == 0)
		count += ft_putchar('0');
	else
	{
		ft_print_hex(num, format);
		count += ft_hex_len(num);
	}
	return (count);
}
