/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calcul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:00:55 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/29 11:08:01 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calcul_delta(t_data *dta)
{
	if (dta->raydir_x == 0)
		dta->deltadist_x = 1e30;
	else
		dta->deltadist_x = fabs(1 / dta->raydir_x);
	if (dta->raydir_y == 0)
		dta->deltadist_y = 1e30;
	else
		dta->deltadist_y = fabs(1 / dta->raydir_y);
}

void	calcul_side_dest(t_data *dta)
{
	if (dta->raydir_x < 0)
	{
		dta->step_x = -1;
		dta->sidedest_x = (dta->p.pos_x - dta->map_x) * dta->deltadist_x;
	}
	else
	{
		dta->step_x = 1;
		dta->sidedest_x = (dta->map_x + 1.0 - dta->p.pos_x) * dta->deltadist_x;
	}
	if (dta->raydir_y < 0)
	{
		dta->step_y = -1;
		dta->sidedest_y = (dta->p.pos_y - dta->map_y) * dta->deltadist_y;
	}
	else
	{
		dta->step_y = 1;
		dta->sidedest_y = (dta->map_y + 1.0 - dta->p.pos_y) * dta->deltadist_y;
	}
}

void	perform_dda(t_data *dta)
{
	while (dta->hit == 0)
	{
		if (dta->sidedest_x < dta->sidedest_y)
		{
			dta->sidedest_x += dta->deltadist_x;
			dta->map_x += dta->step_x;
			dta->side = 0;
		}
		else
		{
			dta->sidedest_y += dta->deltadist_y;
			dta->map_y += dta->step_y;
			dta->side = 1;
		}
		if (dta->real_map[(int)dta->map_x][(int)dta->map_y] == '1')
			dta->hit = 1;
	}
}

void	projected_dist(t_data *dta)
{
	if (dta->side == 0)
		dta->perp_wdist = (dta->sidedest_x - dta->deltadist_x);
	else
		dta->perp_wdist = (dta->sidedest_y - dta->deltadist_y);
	dta->line_h = (int)(dta->height / dta->perp_wdist);
	dta->draw_start = -(dta->line_h) / 2 + dta->height / 2;
	if (dta->draw_start < 0)
		dta->draw_start = 0;
	dta->draw_end = dta->line_h / 2 + dta->height / 2;
	if (dta->draw_end >= dta->height)
		dta->draw_end = dta->height - 1;
}
