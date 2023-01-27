/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:48:23 by yugurlu           #+#    #+#             */
/*   Updated: 2022/10/28 15:59:26 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int a)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(a);
	len += ft_printstr(num);
	free(num);
	return (len);
}

int	ft_printnumber(unsigned int a, char format)
{
	int		len;
	char	*num;

	len = 0;
	if (a == 0)
		return (ft_putchar('0'));
	if (format == 'X' || format == 'x')
	{
		ft_print_hex(a, format);
		return (ft_hex_len(a));
	}
	if (format == 'p')
		return (ft_print_ptr(a, format));
	else
	{
		num = ft_itoa(a);
		len += ft_printstr(num);
		free(num);
	}
	return (len);
}
