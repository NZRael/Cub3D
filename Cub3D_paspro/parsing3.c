/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:04:02 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/29 10:11:56 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	all_parsing(t_data *dta)
{
	// for (int x = 0; dta->map[x] != NULL; x++)
	// 	printf("dta->map[%d] = '%s'\n", x, dta->map[x]);
	ft_initialisation(dta);
	structuration(dta);
	first_parsing(dta);
	parsing_map(dta);
	return (0);
}

void	ft_initialisation(t_data *dta)
{
	dta->NO = NULL;
	dta->SO = NULL;
	dta->EA = NULL;
	dta->WE = NULL;
	dta->C = NULL;
	dta->F = NULL;
	dta->i_color = 0;
	dta->nbr_comma = 0;
	dta->nbr_n = 0;
	dta->nbr_s = 0;
	dta->nbr_e = 0;
	dta->nbr_w = 0;
}

void	after_id(t_data *dta, int start)
{
	int	i;

	i = 0;
	if (!dta->map[start])
		ft_exit(dta, "no map\n");
	while (dta->map[start][i] && dta->map[start][i] != '1' \
			&& dta->map[start][i] != '\0')
	{
		if (dta->map[start][i] == ' ' || dta->map[start][i] == '\t')
			i++;
		else if (dta->map[start][i] == '\0')
			start++;
		else if (dta->map[start][i] == '1')
			break ;
		else
			ft_exit(dta, "Something between ids and map\n");
	}
	dta->start_map = start;
}

int	structuration(t_data *dta)
{
	int	i;
	int	i2;
	int	stop;

	i = 0;
	stop = 6;
	while (i < stop)
	{
		i2 = 0;
		while (dta->map[i][i2] == ' ' || dta->map[i][i2] == '\t')
			i2++;
		if (dta->map[i][i2] == 'N' && dta->map[i][i2 + 1] && dta->map[i][i2 + 1] == 'O')
			dta->NO = dta->map[i];
		if (dta->map[i][i2] == 'W' && dta->map[i][i2 + 1] && dta->map[i][i2 + 1] == 'E')
			dta->WE = dta->map[i];
		if (dta->map[i][i2] == 'S' && dta->map[i][i2 + 1] && dta->map[i][i2 + 1] == 'O')
			dta->SO = dta->map[i];
		if (dta->map[i][i2] == 'E' && dta->map[i][i2 + 1] && dta->map[i][i2 + 1] == 'A')
			dta->EA = dta->map[i];
		if (dta->map[i][i2] == 'C')
			dta->C = dta->map[i];
		if (dta->map[i][i2] == 'F')
			dta->F = dta->map[i];
		if (dta->map[i][i2] == '\0')
			stop++;
		i++;
	}
	after_id(dta, stop);
	return (0);
}
