/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:45:38 by fleriche          #+#    #+#             */
/*   Updated: 2024/04/10 16:02:54 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	all_parsing(t_data *dta, char *file)
{
	ft_initialisation(dta);
	ft_structuration(dta);
	first_parsing(dta);
	parsing_before_map(dta, file);
	parsing_map(dta);
	return (0);
}

void	ft_initialisation(t_data *dta)
{
	dta->no_line = NULL;
	dta->so_line = NULL;
	dta->ea_line = NULL;
	dta->we_line = NULL;
	dta->c_line = NULL;
	dta->f_line = NULL;
	dta->i_color = 0;
	dta->nbr_comma = 0;
	dta->nbr_n = 0;
	dta->nbr_s = 0;
	dta->nbr_e = 0;
	dta->nbr_w = 0;
	dta->stop = 0;
}

void	after_id(t_data *dta, int start)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (dta->map[x])
		x++;
	if (x < start || !dta->map[start])
		ft_exit(dta, "No map");
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
			ft_exit(dta, "y'a une couille entre les id et la map\n");
	}
	dta->start_map = start;
}

int	ft_structuration(t_data *dta)
{
	int	i;
	int	i2;
	int	stop;

	i = -1;
	i2 = 0;
	stop = 6;
	ft_in_structuration(dta, i, i2, &stop);
	after_id(dta, stop);
	return (0);
}

void	ft_in_structuration(t_data *dta, int i, int i2, int *stop)
{
	while (++i < *stop && dta->map[i])
	{
		i2 = 0;
		while (dta->map[i][i2] \
				&& (dta->map[i][i2] == ' ' || dta->map[i][i2] == '\t'))
			i2++;
		if (dta->map[i][i2] == 'N' && dta->map[i][i2 + 1] \
				&& dta->map[i][i2 + 1] == 'O')
			dta->no_line = dta->map[i];
		if (dta->map[i][i2] == 'W' && dta->map[i][i2 + 1] \
				&& dta->map[i][i2 + 1] == 'E')
			dta->we_line = dta->map[i];
		if (dta->map[i][i2] == 'S' && dta->map[i][i2 + 1] \
				&& dta->map[i][i2 + 1] == 'O')
			dta->so_line = dta->map[i];
		if (dta->map[i][i2] == 'E' && dta->map[i][i2 + 1] \
				&& dta->map[i][i2 + 1] == 'A')
			dta->ea_line = dta->map[i];
		if (dta->map[i][i2] == 'C')
			dta->c_line = dta->map[i];
		if (dta->map[i][i2] == 'F')
			dta->f_line = dta->map[i];
		if (dta->map[i][i2] == '\0')
			(*stop)++;
	}
}
