/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:08:30 by fleriche          #+#    #+#             */
/*   Updated: 2024/04/11 13:17:56 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verif_char(t_data *dta, int i, int i2)
{
	if (!(dta->real_map[i][i2] == '0' || dta->real_map[i][i2] == '1' \
			|| dta->real_map[i][i2] == 'N' || dta->real_map[i][i2] == 'S' \
			|| dta->real_map[i][i2] == 'E' || dta->real_map[i][i2] == 'W' \
			|| dta->real_map[i][i2] == ' ' || dta->real_map[i][i2] == '\n'))
		ft_exit(dta, "Invalid map");
	if (dta->real_map[i][i2] == 'N' || dta->real_map[i][i2] == 'S' \
			|| dta->real_map[i][i2] == 'E' || dta->real_map[i][i2] == 'W')
	{
		dta->player_x = i;
		dta->player_y = i2;
	}
}

void	verif_doublon(t_data *dta)
{
	int	nbr_all;

	nbr_all = dta->nbr_n + dta->nbr_s + dta->nbr_e + dta->nbr_w;
	if (nbr_all != 1)
		ft_exit(dta, "Number of player invalid");
}

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

void	create_mapcpy(t_data *dta)
{
	int		i;

	i = 0;
	while (dta->real_map[i] != NULL)
		i++;
	dta->map_cpy = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (dta->real_map[i] != NULL)
	{
		dta->map_cpy[i] = ft_strdup(dta->real_map[i]);
		i++;
	}
	dta->map_cpy[i] = NULL;
	return ;
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
	dta->payer_letter = dta->real_map[dta->player_x][dta->player_y];
	create_mapcpy(dta);
	verif_holes(dta);
	zero_extend(dta);
	ft_boucle(dta);
	ft_replace_map(dta);
	return (0);
}
