/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:00:45 by yugurlu           #+#    #+#             */
/*   Updated: 2022/10/15 02:48:38 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	j;
	char	*cpy;

	j = ft_strlen(s1) + 1;
	cpy = ft_calloc(j, sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1, j);
	return (cpy);
}
