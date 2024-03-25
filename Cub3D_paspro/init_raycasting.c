/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:39:06 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/25 14:52:30 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_p(t_data *dta)
{
	dta->p.pos_x = 14;
	dta->p.pos_y = 10;
	dta->p.dir_x = -1;
	dta->p.dir_y = 0;
	dta->p.plane_x = 0;
	dta->p.plane_y = 0.80;
	dta->p.moveSpeed = 0.15;
	dta->p.rotSpeed = 0.07;
	dta->texheight = 64;
	dta->texwidth = 64;
}

void	init_raycasting(t_data *dta)
{
	int	x;
	// int	color;

	x = 0;
	print_fc(dta);
	while (x < dta->width)
	{
		dta->cameraX = 2 * x / (double)(dta->width) - 1;
		dta->rayDirX = dta->p.dir_x + dta->p.plane_x * dta->cameraX;
		dta->rayDirY = dta->p.dir_y + dta->p.plane_y * dta->cameraX;
		dta->mapX = (int)dta->p.pos_x;
		dta->mapY = (int)dta->p.pos_y;
		calcul_delta(dta);
		dta->hit = 0;
		calcul_side_dest(dta);
		perform_dda(dta);
		projected_dist(dta);
		// color = test_colors(dta);
		// if (dta->side == 1)
		// 	color = color / 2;
		// if (color != -1)
		// 	print_wall(dta, x, color);
		print_wall(dta, x);
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

// int	test_colors(t_data *dta)
// {
// 	int	color;

// 	// printf("dta->realmap[%d][%d] = %c\n", (int)dta->mapX, (int)dta->mapY, dta->real_map[(int)dta->mapX][(int)dta->mapY]);
// 	if (dta->real_map[(int)dta->mapX][(int)dta->mapY] == '1')
// 		color = create_rgb((0 << 16), (0 << 8), 255);
// 	else
// 		color = -1;
// 	return color;
// }

// void	test_texture(t_data *dta)
// {
// 	int 	tex_num;
// 	int		tex_x;
// 	double	wallx;

// 	tex_num = (int)dta->real_map[(int)dta->mapX][(int)dta->mapY];
// 	if (dta->side == 0)
// 		wallx = dta->p.pos_y + dta->perpWallDist * dta->rayDirY;
// 	else
// 		wallx = dta->p.pos_x + dta->perpWallDist * dta->rayDirX;
// 	wallx -= floor(wallx);
// 	tex_x = (int)(wallx * (double)(dta->texwidth));
//       if(dta->side == 0 && dta->rayDirX > 0)
// 	  	tex_x = dta->texwidth - tex_x - 1;
//       if(dta->side == 1 && dta->rayDirY < 0)
// 	  	tex_x = dta->texwidth - tex_x - 1;
// }

void	print_wall(t_data *dta, int x)
{
	int				y;
	unsigned int	color;
	// int	tmp;

	// tmp = 0;
	// if (dta->drawEnd < dta->drawStart)
	// {
	// 	tmp = dta->drawStart;
	// 	dta->drawStart = dta->drawEnd;
	// 	dta->drawEnd = tmp;
	// }
	// if (dta->drawEnd < 0 || dta->drawStart >= dta->height || x < 0 || x >= dta->width)
	// 	return ;
	// if (dta->drawStart < 0)
	// 	dta->drawStart = 0;
	// if (dta->drawEnd >= dta->height)
	// 	dta->drawEnd = dta->height - 1;
	color = 0;
	y = dta->drawStart;
	while (y <= dta->drawEnd)
	{
		//printf("y = %d\n", y);
		color = my_mlx_pixel_get(dta, x, y, 0);
		my_mlx_pixel_put(dta, x, y, color);
		y++;
	}
}
