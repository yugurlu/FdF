/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:57:22 by yugurlu           #+#    #+#             */
/*   Updated: 2022/10/31 11:27:19 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_findpercentsign(va_list args, const char *str)
{
	int	i;
	int	length;

	length = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			length += ft_findformat(args, str[i + 1]);
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	return (length);
}

int	ft_findformat(va_list args, const char c)
{
	int	length;

	length = 0;
	if (c == '%')
		length += ft_putchar('%');
	else if (c == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (c == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		length += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		length += ft_printnumber(va_arg(args, unsigned int), c);
	else if (c == 'X')
		length += ft_printnumber(va_arg(args, unsigned int), c);
	else if (c == 'x')
		length += ft_printnumber(va_arg(args, unsigned int), c);
	else if (c == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long), c);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;

	result = 0;
	va_start(args, str);
	result = ft_findpercentsign(args, str);
	va_end(args);
	return (result);
}
