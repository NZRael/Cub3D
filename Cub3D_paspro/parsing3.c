/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:26:09 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/10 16:43:41 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_color(t_data *dta, char *id)
{
	int		i2;
	int		nombre;
	char	*nbr;

	i2 = dta->i_color;
	while (id[i2] >= '0' && id[i2] <= '9')
		i2++;
	nbr = ft_substr(id, dta->i_color, i2 - dta->i_color + 1);
	if (!nbr[0])
		ft_exit(dta, "Color path invalid");
	dta->i_color = i2;
	while (id[dta->i_color] == ' ' || id[dta->i_color] == '\t' \
			|| id[dta->i_color] == ',')
	{
		if (id[dta->i_color] == ',')
			dta->nbr_comma++;
		dta->i_color++;
	}
	ft_in_init_color(dta, i2, id, nbr);
	nombre = ft_atoi(nbr);
	free(nbr);
	return (nombre);
}

void	ft_in_init_color(t_data *dta, int i2, char *id, char *nbr)
{
	i2 = dta->i_color;
	if (dta->nbr_comma == 2 || dta->nbr_comma == 4)
	{
		while (id[i2] && id[i2] >= '0' && id[i2] <= '9')
			i2++;
		while (id[i2] && id[i2] != '\0')
		{
			if (!(id[i2] == ' ' || id[i2] == '\t' || id[i2] == ',' ))
			{
				free(nbr);
				ft_exit(dta, "Color path invalid");
			}
			i2++;
		}
	}
	return ;
}
