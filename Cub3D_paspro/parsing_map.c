/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:08:30 by fleriche          #+#    #+#             */
/*   Updated: 2024/04/03 17:02:05 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verif_char(t_data *dta, int i, int i2)
{
	if (!(dta->real_map[i][i2] == '0' || dta->real_map[i][i2] == '1' \
			|| dta->real_map[i][i2] == 'N' || dta->real_map[i][i2] == 'S' \
			|| dta->real_map[i][i2] == 'E' || dta->real_map[i][i2] == 'W' \
			|| dta->real_map[i][i2] == ' ' || dta->real_map[i][i2] == '\t' || dta->real_map[i][i2] == '\n'))
		ft_exit(dta, "map pas bon\n");
	if (dta->real_map[i][i2] == 'N' || dta->real_map[i][i2] == 'S' \
			|| dta->real_map[i][i2] == 'E' || dta->real_map[i][i2] == 'W')
	{
		dta->player_x = i;
		dta->player_y = i2;
		printf("player_x = %d\n", dta->player_x);
		printf("player_y = %d\n", dta->player_y);
	}
}

void	verif_doublon(t_data *dta)
{
	int	nbr_all;

	nbr_all = dta->nbr_n + dta->nbr_s + dta->nbr_e + dta->nbr_w;
	if (nbr_all != 1)
		ft_exit(dta, "trop ou pas de N,S,E,W");
}
//printf("nbr_all : %d\n", nbr_all); //DOIT ETRE = 1

void	nbr_char(t_data *dta, int i, int i2)
{
	if (dta->real_map[i][i2] == 'N')
		dta->nbr_n++;
	if (dta->real_map[i][i2] == 'S')
		dta->nbr_s++;
	if (dta->real_map[i][i2] == 'W')
		dta->nbr_w++;
	if (dta->real_map[i][i2] == 'E')
		dta->nbr_e++;
}

void	player_extend(t_data *dta)
{
	int	i;
	int	i2;

	i = dta->start_map;
	while (dta->map_cpy[i])
	{
		i2 = 0;
		while (dta->map_cpy[i][i2] != '\0')
		{
			if (dta->map_cpy[i][i2] == dta->payer_letter)
			{
				if (i == dta->end_map - 1)
					ft_exit(dta, "pas bonnnnn");
				if (dta->map_cpy[i][i2 + 1] == ' ' || dta->map_cpy[i][i2 + 1] == '\t' || dta->map_cpy[i][i2 + 1] == '\0')
					ft_exit(dta, "map ouverte");
				if (dta->map_cpy[i][i2 - 1] == ' ' || dta->map_cpy[i][i2 - 1] == '\t' || dta->map_cpy[i][i2 - 1] == '\0')
					ft_exit(dta, "map ouverte");
				if (dta->map_cpy[i + 1][i2] == ' ' || dta->map_cpy[i + 1][i2] == '\t' || dta->map_cpy[i + 1][i2] == '\0')
					ft_exit(dta, "map ouverte");
				if (dta->map_cpy[i - 1][i2] == ' ' || dta->map_cpy[i - 1][i2] == '\t' || dta->map_cpy[i - 1][i2] == '\0')
					ft_exit(dta, "map ouverte");
				if (dta->map_cpy[i][i2 + 1] == '0' || dta->map_cpy[i][i2 + 1] == '2')
					dta->map_cpy[i][i2 + 1] = dta->payer_letter;
				if (dta->map_cpy[i][i2 - 1] == '0' || dta->map_cpy[i][i2 - 1] == '2')
					dta->map_cpy[i][i2 - 1] = dta->payer_letter;
				if (dta->map_cpy[i + 1][i2] == '0' || dta->map_cpy[i + 1][i2] == '2')
					dta->map_cpy[i + 1][i2] = dta->payer_letter;
				if (dta->map_cpy[i - 1][i2] == '0' || dta->map_cpy[i - 1][i2] == '2')
					dta->map_cpy[i - 1][i2] = dta->payer_letter;
				// printf("%d\n", i);
				// printf("%d\n", i2);
				// printf("%s\n", dta->map_cpy[i]);
				// printf("%s\n", dta->map_cpy[32]);
				// printf("%c\n", dta->map_cpy[i][i2]);
				// printf("lol1\n");
			}
			i2++;
			// printf("%d\n", i2);
		}
		i++;
	}
	verif_holes(dta);
}

void	verif_holes(t_data *dta)
{
	int	i;
	int	i2;

	i = dta->start_map;
	while (dta->map_cpy[i])
	{
		i2 = 0;
		while (dta->map_cpy[i][i2] != '\0')
		{
			if (dta->map_cpy[i][i2] == '0')
			{
				dta->map_cpy[i][i2] = '2';
				player_extend(dta);
				// printf("lol2\n");
			}
			i2++;
		}
		i++;
	}
}

int	parsing_map(t_data *dta)
{
	int	i;
	int	i2;

	i = dta->start_map;
	while (i <= dta->end_map)
	{
		if (dta->real_map[i])
			i2 = 0;
		while (dta->real_map[i][i2] != '\0')
		{
			verif_char(dta, i, i2);
			nbr_char(dta, i, i2);
			i2++;
		}
		i++;
	}
	verif_doublon(dta);
	dta->map_cpy = dta->real_map;
	dta->payer_letter = dta->real_map[dta->player_x][dta->player_y];
	// printf("%c", dta->payer_letter);
	verif_holes(dta);
	return (0);
}
