/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_before_map2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:14:31 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/10 16:48:57 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	search_real_start(t_data *dta)
{
	int	i;
	int	j;

	i = 0;
	while (dta->real_map[i])
	{
		j = 0;
		while (dta->real_map[i][j] == ' ' || dta->real_map[i][j] == '\t')
			j++;
		if (dta->real_map[i][j] && dta->real_map[i][j] != '1')
			i++;
		else
		{
			dta->start_map = i;
			break ;
		}
	}
}

void	search_end_map(t_data *dta)
{
	int	i;
	int	j;

	i = 0;
	while (dta->real_map[i] != NULL)
		i++;
	i--;
	while (i >= dta->start_map)
	{
		j = 0;
		while (dta->real_map[i][j] && (dta->real_map[i][j] == '\n' \
				|| dta->real_map[i][j] == ' ' || dta->real_map[i][j] == '\t'))
			j++;
		if (dta->real_map[i][j] && dta->real_map[i][j] != '\0')
		{
			dta->end_map = i;
			break ;
		}
		else
			i--;
	}
	return ;
}
