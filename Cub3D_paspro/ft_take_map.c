/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:59:35 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/27 14:58:21 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_take_map(t_data *dta)
{
	int			x;
	size_t		y;
	int			i;

	x = 0;
	i = 0;
	dta->real_map = malloc(sizeof(char *) * (ft_count_take_map(dta) + 1));
	while (dta->map[x] != NULL)
	{
		y = 0;
		while (dta->map[x][y] == ' ' || dta->map[x][y] == '\t' \
			|| dta->map[x][y] == '1')
			y++;
		if (y >= ft_strlen(dta->map[x]))
		{
			while (dta->map[x] != NULL)
			{
				dta->real_map[i] = ft_strdup(dta->map[x]);
				i++;
				x++;
			}
			dta->real_map[i] = NULL;
			break ;
		}
		x++;
	}
	return ;
}

int	ft_count_take_map(t_data *dta)
{
	int			x;
	size_t		y;
	int			i;

	x = 0;
	i = 0;
	while (dta->map[x] != NULL)
	{
		y = 0;
		while (dta->map[x][y] == ' ' || dta->map[x][y] == '\t'
			|| dta->map[x][y] == '1')
			y++;
		if (y >= ft_strlen(dta->map[x]))
		{
			while (dta->map[x] != NULL)
			{
				i++;
				x++;
			}
			break ;
		}
		x++;
	}
	return (i);
}
