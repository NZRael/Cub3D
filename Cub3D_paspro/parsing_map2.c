/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:49:35 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/11 13:30:19 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	zero_extend(t_data *dta)
{
	int	i;
	int	j;

	i = dta->start_map;
	while (dta->real_map[i] != NULL)
	{
		j = 0;
		while (dta->real_map[i][j] && dta->real_map[i][j] != '\0')
		{
			if (dta->real_map[i][j] == '0')
				ft_in_zero_extend(dta, i, j);
			j++;
		}
		i++;
	}
}

void	ft_in_zero_extend(t_data *dta, int i, int j)
{
	if (!dta->real_map[i + 1])
		ft_exit(dta, "braaaa\n");
	if (dta->real_map[i][j + 1] && dta->real_map[i][j + 1] != '0'
			&& dta->real_map[i][j + 1] != '1'
			&& dta->real_map[i][j + 1] != dta->payer_letter)
		ft_exit(dta, "puteuh a droite\n");
	if (dta->real_map[i][j - 1] && dta->real_map[i][j - 1] != '0'
			&& dta->real_map[i][j - 1] != '1'
			&& dta->real_map[i][j + -1] != dta->payer_letter)
		ft_exit(dta, "puteuh a gauche\n");
	if (dta->real_map[i + 1] && dta->real_map[i + 1][j]
			&& dta->real_map[i + 1][j] != '0'
			&& dta->real_map[i + 1][j] != '1'
			&& dta->real_map[i + 1][j] != dta->payer_letter)
		ft_exit(dta, "puteuh en bas\n");
	if (dta->real_map[i - 1][j] && dta->real_map[i - 1][j] != '0'
			&& dta->real_map[i - 1][j] != '1'
			&& dta->real_map[i - 1][j] != dta->payer_letter)
		ft_exit(dta, "puteuh en haut\n");
}

void	ft_replace_map(t_data *dta)
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
				ft_in_replace_map(dta, i, i2);
			i2++;
		}
		i++;
	}
	dta->stop--;
	if (dta->stop >= 0)
		ft_replace_map(dta);
	else
		projet_fini(dta);
}

void	ft_in_replace_map(t_data *dta, int i, int i2)
{
	if (dta->map_cpy[i][i2 + 1] && (dta->map_cpy[i][i2 + 1] == '0'
			|| dta->map_cpy[i][i2 + 1] == '1'
			|| dta->map_cpy[i][i2 + 1] == '2'))
		dta->map_cpy[i][i2 + 1] = dta->payer_letter;
	if (i2 > 0 && (dta->map_cpy[i][i2 - 1] == '0'
		|| dta->map_cpy[i][i2 - 1] == '1'
		|| dta->map_cpy[i][i2 + 1] == '2'))
		dta->map_cpy[i][i2 - 1] = dta->payer_letter;
	if (dta->map_cpy[i + 1]
		&& i2 <= (int)ft_strlen(dta->map_cpy[i + 1])
		&& (dta->map_cpy[i + 1][i2] == '0'
		|| dta->map_cpy[i + 1][i2] == '1'
		|| dta->map_cpy[i][i2 + 1] == '2'))
		dta->map_cpy[i + 1][i2] = dta->payer_letter;
	if (dta->map_cpy[i - 1]
		&& i2 <= (int)ft_strlen(dta->map_cpy[i - 1])
		&& (dta->map_cpy[i - 1][i2] == '0'
		|| dta->map_cpy[i - 1][i2] == '1'
		|| dta->map_cpy[i][i2 + 1] == '2'))
		dta->map_cpy[i - 1][i2] = dta->payer_letter;
}

void	relance(t_data *dta)
{
	int	i;
	int	i2;

	i = dta->start_map;
	while (i <= dta->end_map)
	{
		i2 = 0;
		while (dta->map_cpy[i][i2] != '\0')
		{
			dta->stop++;
			i2++;
		}
		i++;
	}
}
