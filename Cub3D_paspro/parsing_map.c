/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:08:30 by fleriche          #+#    #+#             */
/*   Updated: 2024/04/09 14:02:55 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verif_char(t_data *dta, int i, int i2)
{
	if (!(dta->real_map[i][i2] == '0' || dta->real_map[i][i2] == '1' \
			|| dta->real_map[i][i2] == 'N' || dta->real_map[i][i2] == 'S' \
			|| dta->real_map[i][i2] == 'E' || dta->real_map[i][i2] == 'W' \
			|| dta->real_map[i][i2] == ' ' || dta->real_map[i][i2] == '\n'))
		ft_exit(dta, "map pas bon\n");
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
		ft_exit(dta, "trop ou pas de N,S,E,W");
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
	relance(dta);
	le_vrai_one_extend(dta);
	return (0);
}

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

// void	one_extend(t_data *dta)
// {
// 	int	i;
// 	int	j;

// 	i = dta->start_map;
// 	while (dta->real_map[i] != NULL)
// 	{
// 		j = 0;
// 		while (dta->real_map[i][j] && dta->real_map[i][j] != '\0')
// 		{
// 			if (dta->real_map[i][j] == '1')
// 			{
// 				if (dta->real_map[i][j + 1] && (dta->real_map[i][j + 1] == '0' || dta->real_map[i][j + 1] == '1' || dta->real_map[i][j + 1] == dta->payer_letter))
// 					j++;
// 				else if (dta->real_map[i][j - 1] && (dta->real_map[i][j - 1] == '0' || dta->real_map[i][j - 1] == '1' || dta->real_map[i][j + -1] == dta->payer_letter))
// 					j++;
// 				else if (dta->real_map[i + 1] && (dta->real_map[i + 1][j] == '0' || dta->real_map[i + 1][j] == '1' || dta->real_map[i + 1][j] == dta->payer_letter))
// 					j++;
// 				else if (dta->real_map[i - 1][j] && (dta->real_map[i - 1][j] == '0' || dta->real_map[i - 1][j] == '1' || dta->real_map[i - 1][j] == dta->payer_letter))
// 					j++;
// 				else if (dta->real_map[i][j] && dta->real_map[i][j] != '1')
// 					j++;
// 				else
// 					ft_exit(dta, "A 1 is not in the map");
// 			}
// 			else
// 				j++;
// 		}
// 		i++;
// 	}
// }
