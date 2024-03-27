/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:45:47 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/27 17:36:15 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strjoinfree2(char *stock, char *tmp)
{
	char	*str;

	str = ft_strjoin(stock, tmp);
	if (stock)
		free (stock);
	return (str);
}

void	read_map(char *map, t_data *dta)
{
	int		file;
	char	*line;
	char	*line2;
	int		i;

	i = 0;
	file = open(map, O_RDONLY, 0777);
	line = get_next_line(file);
	while (1)
	{
		i++;
		line2 = get_next_line(file);
		if (!line2)
			break ;
		line = ft_strjoinfree2(line, line2);
		free(line2);
	}
	if (line == NULL)
		ft_exit(dta, "line NULL on file");
	dta->map = ft_split(line, '\n');
	free(line);
	if (i == 0)
		ft_exit(dta, "Nothing in the file");
	return ;
}
