/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:52:14 by yugurlu           #+#    #+#             */
/*   Updated: 2022/11/02 17:41:53 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	int		byte;
	char	*str;

	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	byte = 1;
	while (ft_strchr(buffer) && byte != 0)
	{
		byte = read(fd, str, BUFFER_SIZE);
		if (byte == -1)
		{
			free(str);
			return (0);
		}
		str[byte] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_line(buffer);
	buffer = ft_clean(buffer);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDWR, 777);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	system("leaks a.out");
}
*/
