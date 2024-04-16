/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:48:56 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/27 17:24:09 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero_gnl(char *sbase, size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		sbase[i] = '\0';
		i++;
		n--;
	}
}

char	*ft_calloc_gnl(size_t count, size_t size)
{
	char	*str;

	if ((count >= 922337200000000000)
		|| (size >= 922337200000000000))
		return (0);
	str = malloc(sizeof(char) * (count * size));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	ft_bzero_gnl(str, count * size);
	return (str);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

static char	*ft_read(int fd, char *sbase)
{
	char	*buff;
	int		rd;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd = 1;
	while (rd != 0 && !ft_strchr_gnl(sbase, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		sbase = ft_strjoin_gnl(sbase, buff);
	}
	free(buff);
	return (sbase);
}

char	*get_next_line(int fd)
{
	static char	*sbase;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		if (sbase)
			free(sbase);
		sbase = NULL;
		return (NULL);
	}
	sbase = ft_read(fd, sbase);
	if (!sbase)
		return (NULL);
	line = ft_getline(sbase);
	sbase = ft_newsbase(sbase);
	return (line);
}
