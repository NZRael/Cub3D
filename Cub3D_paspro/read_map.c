/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:45:47 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/27 12:51:00 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	read_map(char *map, t_data *dta)
{
	int		fd;
	char	*buffer;
	ssize_t	nread;
////////////////////////////// FLORIAN TA SOEUR REFAIT MOI CA
	nread = 1;
	buffer = malloc(sizeof(char) * 829);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_exit(dta, "Error opening file");
	nread = read(fd, buffer, 829);
	if (nread < -1)
		ft_exit(dta, "Error opening file");
	dta->map_str = ft_strdup(buffer);
	dta->map = ft_split(dta->map_str, '\n');
	close(fd);
	free(buffer);
}
