/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:45:47 by fleriche          #+#    #+#             */
/*   Updated: 2023/12/20 11:12:24 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	read_map(char *map, t_data *dta)
{
	int		fd;
	char	*buffer;
	ssize_t	nread;

	nread = 1;
	buffer = malloc(sizeof(char) * 1024);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_exit(dta, "Error opening file");
	nread = read(fd, buffer, 1024);
	if (nread < -1)
		ft_exit(dta, "Error opening file");
	dta->map_str = buffer;
	dta->map = ft_split(buffer, '\n');
	close(fd);
	free(buffer);
}
