/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calcul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:00:55 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/28 10:25:26 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calcul_delta(t_data *dta)
{
	if (dta->rayDirX == 0)
		dta->deltaDistX = 1e30;
	else
		dta->deltaDistX = fabs(1 / dta->rayDirX);
	if (dta->rayDirY == 0)
		dta->deltaDistY = 1e30;
	else
		dta->deltaDistY = fabs(1 / dta->rayDirY);
}

void	calcul_side_dest(t_data *dta)
{
	if (dta->rayDirX < 0)
	{
		dta->stepX = -1;
		dta->sideDistX = (dta->p.pos_x - dta->mapX) * dta->deltaDistX;
	}
	else
	{
		dta->stepX = 1;
		dta->sideDistX = (dta->mapX + 1.0 - dta->p.pos_x) * dta->deltaDistX;
	}
	if (dta->rayDirY < 0)
	{
		dta->stepY = -1;
		dta->sideDistY = (dta->p.pos_y - dta->mapY) * dta->deltaDistY;
	}
	else
	{
		dta->stepY = 1;
		dta->sideDistY = (dta->mapY + 1.0 - dta->p.pos_y) * dta->deltaDistY;
	}
}

void	perform_dda(t_data *dta)
{
	while (dta->hit == 0)
	{
		if (dta->sideDistX < dta->sideDistY)
		{
			dta->sideDistX += dta->deltaDistX;
			dta->mapX += dta->stepX;
			dta->side = 0;
		}
		else
		{
			dta->sideDistY += dta->deltaDistY;
			dta->mapY += dta->stepY;
			dta->side = 1;
		}
		if (dta->real_map[(int)dta->mapX][(int)dta->mapY] == '1')
			dta->hit = 1;
	}
}

void	projected_dist(t_data *dta)
{
	if (dta->side == 0)
		dta->perpWallDist = (dta->sideDistX - dta->deltaDistX);
	else
		dta->perpWallDist = (dta->sideDistY - dta->deltaDistY);
	dta->lineHeight = (int)(dta->height / dta->perpWallDist);
	dta->drawStart = -(dta->lineHeight) / 2 + dta->height / 2;
	if (dta->drawStart < 0)
		dta->drawStart = 0;
	dta->drawEnd = dta->lineHeight / 2 + dta->height / 2;
	if (dta->drawEnd >= dta->height)
		dta->drawEnd = dta->height - 1;
}
