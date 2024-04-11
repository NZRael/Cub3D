/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:23:10 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/11 13:30:50 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verif_holes(t_data *dta)
{
	int	i;
	int	i2;

	i = dta->start_map;
	while (i <= dta->end_map)
	{
		i2 = 0;
		while (dta->map_cpy[i][i2] != '\0')
		{
			if (i2 == 0 && (dta->map_cpy[i][i2] != '1'
				&& dta->map_cpy[i][i2] != ' '))
				ft_exit(dta, "map etrevuo");
			if (i == dta->start_map && (dta->map_cpy[i][i2] != '1'
				&& dta->map_cpy[i][i2] != ' ' && dta->map_cpy[i][i2] != '\n'))
				ft_exit(dta, "map etrevuo");
			if (dta->map_cpy[i][i2] == '0')
			{
				dta->map_cpy[i][i2] = '2';
				player_extend(dta);
			}
			i2++;
		}
		i++;
	}
}

void	player_extend(t_data *dta)
{
	int	i;
	int	i2;

	i = dta->start_map;
	while (i <= dta->end_map)
	{
		i2 = 0;
		while (dta->map_cpy[i][i2] != '\0')
		{
			if (dta->map_cpy[i][i2] && dta->map_cpy[i][i2] == dta->payer_letter)
				ft_in_player_extend(dta, i, i2);
			i2++;
		}
		i++;
	}
	verif_holes(dta);
}

void	ft_in_player_extend(t_data *dta, int i, int j)
{
	if (dta->map_cpy[i][j + 1] && (dta->map_cpy[i][j + 1] == ' '
		|| dta->map_cpy[i][j + 1] == '\t' || dta->map_cpy[i][j + 1] == '\0'))
		ft_exit(dta, "map ouverte");
	if (dta->map_cpy[i][j - 1] && (dta->map_cpy[i][j - 1] == ' '
		|| dta->map_cpy[i][j - 1] == '\t' || dta->map_cpy[i][j - 1] == '\0'))
		ft_exit(dta, "map ouverte");
	if (dta->map_cpy[i + 1] && dta->map_cpy[i + 1][j]
		&& (dta->map_cpy[i + 1][j] == ' '
		|| dta->map_cpy[i + 1][j] == '\t' || dta->map_cpy[i + 1][j] == '\0'))
		ft_exit(dta, "map ouverte");
	if (dta->map_cpy[i - 1][j] && (dta->map_cpy[i - 1][j] == ' '
		|| dta->map_cpy[i - 1][j] == '\t' || dta->map_cpy[i - 1][j] == '\0'))
		ft_exit(dta, "map ouverte");
	if (dta->map_cpy[i][j + 1] && (dta->map_cpy[i][j + 1] == '0'
		|| dta->map_cpy[i][j + 1] == '2'))
		dta->map_cpy[i][j + 1] = dta->payer_letter;
	if (dta->map_cpy[i][j - 1] && (dta->map_cpy[i][j - 1] == '0'
		|| dta->map_cpy[i][j - 1] == '2'))
		dta->map_cpy[i][j - 1] = dta->payer_letter;
	if (dta->map_cpy[i + 1] && dta->map_cpy[i + 1][j]
		&& (dta->map_cpy[i + 1][j] == '0' || dta->map_cpy[i + 1][j] == '2'))
		dta->map_cpy[i + 1][j] = dta->payer_letter;
	if (dta->map_cpy[i - 1][j] && (dta->map_cpy[i - 1][j] == '0'
		|| dta->map_cpy[i - 1][j] == '2'))
		dta->map_cpy[i - 1][j] = dta->payer_letter;
}

void	projet_fini(t_data *dta)
{
	int	i;
	int	i2;

	i = dta->start_map;
	while (i <= dta->end_map)
	{
		i2 = 0;
		while (dta->map_cpy[i][i2] != '\0')
		{
			if (dta->map_cpy[i][i2] == ' '
				|| dta->map_cpy[i][i2] == dta->payer_letter
				|| dta->map_cpy[i][i2] == '\n')
				i2++;
			else
				ft_exit(dta, "TOI LA VIENS LA (projet fini)");
		}
		i++;
	}
}
