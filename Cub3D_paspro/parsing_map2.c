/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:49:35 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/10 16:51:46 by sboetti          ###   ########.fr       */
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
			//printf("dta->real_map[%d][%d] = %c\n", i, j, dta->real_map[i][j]);
			if (dta->real_map[i][j] == '0')
			{
				if (!dta->real_map[i + 1])
					ft_exit(dta, "braaaa\n");
				if (dta->real_map[i][j + 1] && dta->real_map[i][j + 1] != '0' && dta->real_map[i][j + 1] != '1' && dta->real_map[i][j + 1] != dta->payer_letter)
					ft_exit(dta, "puteuh a droite\n");
				if (dta->real_map[i][j - 1] && dta->real_map[i][j - 1] != '0' && dta->real_map[i][j - 1] != '1' && dta->real_map[i][j + -1] != dta->payer_letter)
					ft_exit(dta, "puteuh a gauche\n");
				if (dta->real_map[i + 1] && dta->real_map[i + 1][j] && dta->real_map[i + 1][j] != '0' && dta->real_map[i + 1][j] != '1' && dta->real_map[i + 1][j] != dta->payer_letter)
					ft_exit(dta, "puteuh en bas\n");
				if (dta->real_map[i - 1][j] && dta->real_map[i - 1][j] != '0' && dta->real_map[i - 1][j] != '1' && dta->real_map[i - 1][j] != dta->payer_letter)
					ft_exit(dta, "puteuh en haut\n");
			}
			j++;
		}
		i++;
	}
}

void	le_vrai_one_extend(t_data *dta)
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
			{
				if (dta->map_cpy[i][i2 + 1] && (dta->map_cpy[i][i2 + 1] == '0' || dta->map_cpy[i][i2 + 1] == '1'|| dta->map_cpy[i][i2 + 1] == '2'))
					dta->map_cpy[i][i2 + 1] = dta->payer_letter;
				if (i2 > 0 && (dta->map_cpy[i][i2 - 1] == '0' || dta->map_cpy[i][i2 - 1] == '1' || dta->map_cpy[i][i2 + 1] == '2'))
					dta->map_cpy[i][i2 - 1] = dta->payer_letter;
				if (dta->map_cpy[i + 1] && i2 <= (int)ft_strlen(dta->map_cpy[i + 1]) && (dta->map_cpy[i + 1][i2] == '0' || dta->map_cpy[i + 1][i2] == '1' || dta->map_cpy[i][i2 + 1] == '2'))
					dta->map_cpy[i + 1][i2] = dta->payer_letter;
				if (dta->map_cpy[i - 1] && i2 <= (int)ft_strlen(dta->map_cpy[i - 1]) && (dta->map_cpy[i - 1][i2] == '0' || dta->map_cpy[i - 1][i2] == '1' || dta->map_cpy[i][i2 + 1] == '2'))
					dta->map_cpy[i - 1][i2] = dta->payer_letter;
			}
			i2++;
		}
		i++;
	}
	dta->stop--;
	if (dta->stop >= 0)
		le_vrai_one_extend(dta);
	else
		projet_fini(dta);
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
			if (dta->map_cpy[i][i2] == ' ' || dta->map_cpy[i][i2] == dta->payer_letter || dta->map_cpy[i][i2] == '\n')
				i2++;
			else
				ft_exit(dta, "TOI LA VIENS LA (projet fini)");
		}
		i++;
	}
}

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
			if (i2 == 0 && (dta->map_cpy[i][i2] != '1' && dta->map_cpy[i][i2] != ' '))
				ft_exit(dta, "map etrevuo");
			if (i == dta->start_map && (dta->map_cpy[i][i2] != '1' && dta->map_cpy[i][i2] != ' ' && dta->map_cpy[i][i2] != '\n'))
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
			{
				if (dta->map_cpy[i][i2 + 1] && (dta->map_cpy[i][i2 + 1] == ' ' || dta->map_cpy[i][i2 + 1] == '\t' || dta->map_cpy[i][i2 + 1] == '\0'))
					ft_exit(dta, "map ouverte");
				if (dta->map_cpy[i][i2 - 1] && (dta->map_cpy[i][i2 - 1] == ' ' || dta->map_cpy[i][i2 - 1] == '\t' || dta->map_cpy[i][i2 - 1] == '\0'))
					ft_exit(dta, "map ouverte");
				if (dta->map_cpy[i + 1] && dta->map_cpy[i + 1][i2] && (dta->map_cpy[i + 1][i2] == ' ' || dta->map_cpy[i + 1][i2] == '\t' || dta->map_cpy[i + 1][i2] == '\0'))
					ft_exit(dta, "map ouverte");
				if (dta->map_cpy[i - 1][i2] && (dta->map_cpy[i - 1][i2] == ' ' || dta->map_cpy[i - 1][i2] == '\t' || dta->map_cpy[i - 1][i2] == '\0'))
					ft_exit(dta, "map ouverte");
				if (dta->map_cpy[i][i2 + 1] && (dta->map_cpy[i][i2 + 1] == '0' || dta->map_cpy[i][i2 + 1] == '2'))
					dta->map_cpy[i][i2 + 1] = dta->payer_letter;
				if (dta->map_cpy[i][i2 - 1] && (dta->map_cpy[i][i2 - 1] == '0' || dta->map_cpy[i][i2 - 1] == '2'))
					dta->map_cpy[i][i2 - 1] = dta->payer_letter;
				if (dta->map_cpy[i + 1] && dta->map_cpy[i + 1][i2] && (dta->map_cpy[i + 1][i2] == '0' || dta->map_cpy[i + 1][i2] == '2'))
					dta->map_cpy[i + 1][i2] = dta->payer_letter;
				if (dta->map_cpy[i - 1][i2] && (dta->map_cpy[i - 1][i2] == '0' || dta->map_cpy[i - 1][i2] == '2'))
					dta->map_cpy[i - 1][i2] = dta->payer_letter;
			}
			i2++;
		}
		i++;
	}
	verif_holes(dta);
}
