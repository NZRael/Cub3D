/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:45:47 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/27 17:24:55 by sboetti          ###   ########.fr       */
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
	char	*tab;
	char	*tab2;
	int		i;

	i = 0;
	file = open(map, O_RDONLY, 0777);
	tab = get_next_line(file);
	while (1)
	{
		i++;
		tab2 = get_next_line(file);
		if (!tab2)
			break ;
		tab = ft_strjoinfree2(tab, tab2);
		free(tab2);
	}
	if (tab == NULL)
		return ;
	dta->map = ft_split(tab, '\n');
	free(tab);
	return ;
}
