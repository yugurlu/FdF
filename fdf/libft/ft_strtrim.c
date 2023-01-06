/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:42:12 by yugurlu           #+#    #+#             */
/*   Updated: 2022/10/15 19:41:34 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	first;
	size_t	len;

	first = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[first]))
		first++;
	while (ft_strrchr(set, s1[len]))
		len--;
	if (ft_strlen(s1) < first)
		return (ft_strdup(""));
	trim = ft_substr(s1, first, (len - first) + 1);
	if (!trim)
		return (NULL);
	return (trim);
}
