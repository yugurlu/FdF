/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:55:52 by yugurlu           #+#    #+#             */
/*   Updated: 2022/11/02 17:41:35 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *lft_str, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!lft_str)
	{
		lft_str = malloc(1);
		lft_str[0] = '\0';
	}
	if (!buff)
		return (0);
	str = malloc(ft_strlen(lft_str) + ft_strlen(buff) + 1);
	if (!str)
		return (0);
	i = -1;
	while (lft_str[++i] != '\0')
		str[i] = lft_str[i];
	j = 0;
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(lft_str);
	return (str);
}

char	*ft_line(char *handle)
{
	int		i;
	char	*str;

	i = 0;
	if (!handle[i])
		return (0);
	while (handle[i] && handle[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (handle[i] && handle[i] != '\n')
	{
		str[i] = handle[i];
		i++;
	}
	if (handle[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_clean(char *handle)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (handle[i] && handle[i] != '\n')
		i++;
	if (!handle[i])
	{
		free(handle);
		return (0);
	}
	str = malloc(ft_strlen(handle) - i + 1);
	i++;
	while (handle[i])
		str[j++] = handle[i++];
	str[j] = '\0';
	free(handle);
	return (str);
}
