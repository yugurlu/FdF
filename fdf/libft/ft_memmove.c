/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:26:29 by yugurlu           #+#    #+#             */
/*   Updated: 2022/10/13 20:45:56 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!src && !dst)
		return (0);
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
