/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:39:06 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/28 16:58:34 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player(t_data *dta)
{
	dta->p.pos_x = 14 + 0.5;
	dta->p.pos_y = 10 + 0.5;
	if (dta->map[dta->player_x][dta->player_y] == 'W')
		init_direction_w(dta);
	else if (dta->map[dta->player_x][dta->player_y] == 'E')
		init_direction_e(dta);
	else if (dta->map[dta->player_x][dta->player_y] == 'S')
		init_direction_s(dta);
	else if (dta->map[dta->player_x][dta->player_y] == 'N')
		init_direction_n(dta);
}

void	init_direction_w(t_data *dta)
{
	dta->p.dir_x = 0;
	dta->p.dir_y = -1;
	dta->p.plane_x = -0.80;
	dta->p.plane_y = 0;
}

void	init_direction_e(t_data *dta)
{
	dta->p.dir_x = 0;
	dta->p.dir_y = 1;
	dta->p.plane_x = 0.80;
	dta->p.plane_y = 0;
}

void	init_direction_s(t_data *dta)
{
	dta->p.dir_x = 1;
	dta->p.dir_y = 0;
	dta->p.plane_x = 0;
	dta->p.plane_y = -0.80;
}

void	init_direction_n(t_data *dta)
{
	dta->p.dir_x = -1;
	dta->p.dir_y = 0;
	dta->p.plane_x = 0;
	dta->p.plane_y = 0.80;
}
