/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:39:06 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/20 16:13:53 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player(t_data *dta)
{
	dta->player.pos_x = 14;
	dta->player.pos_y = 10;
	dta->player.dir_x = -1;
	dta->player.dir_y = 0;
	dta->player.plane_x = 0;
	dta->player.plane_y = 0.66;
	dta->player.moveSpeed = 0.15;
	dta->player.rotSpeed = 0.05;
}

void	init_raycasting(t_data *dta)
{
	int	x;
	int	color;

	x = 0;
	load_textures(dta);
	while (x < dta->width)
	{
		dta->cameraX = 2 * x / (double)(dta->width) - 1;
		dta->rayDirX = dta->player.dir_x + dta->player.plane_x * dta->cameraX;
		dta->rayDirY = dta->player.dir_y + dta->player.plane_y * dta->cameraX;
		dta->mapX = (int)dta->player.pos_x;
		dta->mapY = (int)dta->player.pos_y;
		calcul_delta(dta);
		dta->hit = 0;
		calcul_side_dest(dta);
		perform_dda(dta);
		projected_dist(dta);
		color = test_texture(dta);
		if (dta->side == 1)
			color = color / 2;
		if (color != -1)
			print_wall(dta, x, color);
		x++;
	}
	mlx_put_image_to_window(dta->mlx.mlx_ptr, dta->mlx.win_ptr, dta->mlx.img, 0, 0);
}

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
		dta->sideDistX = (dta->player.pos_x - dta->mapX) * dta->deltaDistX;
	}
	else
	{
		dta->stepX = 1;
		dta->sideDistX = (dta->mapX + 1.0 - dta->player.pos_x) * dta->deltaDistX;
	}
	if (dta->rayDirY < 0)
	{
		dta->stepY = -1;
		dta->sideDistY = (dta->player.pos_y - dta->mapY) * dta->deltaDistY;
	}
	else
	{
		dta->stepY = 1;
		dta->sideDistY = (dta->mapY + 1.0 - dta->player.pos_y) * dta->deltaDistY;
	}
}

void	perform_dda(t_data *dta)
{
	while(dta->hit == 0)
	{
		if(dta->sideDistX < dta->sideDistY)
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

int	test_texture(t_data *dta)
{
	int	color;

	// printf("dta->realmap[%d][%d] = %c\n", (int)dta->mapX, (int)dta->mapY, dta->real_map[(int)dta->mapX][(int)dta->mapY]);
	if (dta->real_map[(int)dta->mapX][(int)dta->mapY] == '1')
		color = (0 << 16) | (0 << 8) | 255;
	else
		color = -1;
	return color;
}

void	print_wall(t_data *dta, int x, int color)
{
	int y;
	int	tmp;

	tmp = 0;
	if (dta->drawEnd < dta->drawStart)
	{
		tmp = dta->drawStart;
		dta->drawStart = dta->drawEnd;
		dta->drawEnd = tmp;
	}
	if (dta->drawEnd < 0 || dta->drawStart >= dta->height || x < 0 || x >= dta->width)
		return ;
	if (dta->drawStart < 0)
		dta->drawStart = 0;
	if (dta->drawEnd >= dta->height)
		dta->drawEnd = dta->height - 1;
	y = dta->drawStart;
    while (y <= dta->drawEnd)
    {
        my_mlx_pixel_put(dta, x, y, color);
        y++;
    }
}
