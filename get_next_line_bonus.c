/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puttasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:00:04 by puttasa           #+#    #+#             */
/*   Updated: 2022/09/28 00:51:33 by puttasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	if (!buf[fd])
	{
		buf[fd] = malloc(1);
		buf[fd][0] = '\0';
	}
	buf[fd] = ft_readfile(buf[fd], fd);
	if (!buf[fd])
	{
		free(buf[fd]);
		return (0);
	}
	line = ft_getline(buf[fd]);
	buf[fd] = ft_extraline(buf[fd]);
	return (line);
}

char	*ft_readfile(char *buf, int fd)
{
	char	*tmp;
	int		checkread;

	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (0);
	checkread = 1;
	while (checkread > 0)
	{
		checkread = read(fd, tmp, BUFFER_SIZE);
		if (checkread < 0)
		{
			free(tmp);
			return (0);
		}
		tmp[checkread] = '\0';
		buf = ft_strjoin(buf, tmp);
		if (ft_strrchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buf);
}

char	*ft_getline(char *buf)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen_mod(buf, '\n');
	if (!buf[0])
		return (0);
	if (buf[len] == '\n')
		len++;
	tmp = ft_substr(buf, 0, len);
	return (tmp);
}

char	*ft_extraline(char *buf)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen_mod(buf, '\n');
	if (!buf[len])
	{
		free(buf);
		return (0);
	}
	if (buf[len] == '\n')
		len++;
	tmp = ft_substr(buf, len, ft_strlen_mod(&buf[len], '\0'));
	free(buf);
	return (tmp);
}
