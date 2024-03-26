/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:39:06 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/26 15:29:51 by sboetti          ###   ########.fr       */
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

void    init_direction_w(t_data *dta)
{
    dta->p.dir_x = 0;
    dta->p.dir_y = -1;
    dta->p.plane_x = -0.80;
    dta->p.plane_y = 0;
}

void    init_direction_e(t_data *dta)
{
    dta->p.dir_x = 0;
    dta->p.dir_y = 1;
    dta->p.plane_x = 0.80;
    dta->p.plane_y = 0;
}

void    init_direction_s(t_data *dta)
{
    dta->p.dir_x = 1;
    dta->p.dir_y = 0;
    dta->p.plane_x = 0;
    dta->p.plane_y = -0.80;
}

void    init_direction_n(t_data *dta)
{
    dta->p.dir_x = -1;
    dta->p.dir_y = 0;
    dta->p.plane_x = 0;
    dta->p.plane_y = 0.80;
}

void	img_renderer(t_data *dta)
{
	mlx_destroy_image(dta->mlx.mlx_ptr, dta->mlx.img);
	dta->mlx.img = mlx_new_image(dta->mlx.mlx_ptr, dta->width, dta->height);
	dta->mlx.addr = mlx_get_data_addr(dta->mlx.img, &dta->mlx.bits_p_pix,
			&dta->mlx.l_length, &dta->mlx.endian);
	init_raycasting(dta);
	mlx_put_image_to_window(dta->mlx.mlx_ptr, dta->mlx.win_ptr, dta->mlx.img, 0, 0);
}

void	init_raycasting(t_data *dta)
{
	int	x;

	x = 0;
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
		calcul_texture(dta);
		print_fc(dta, x);
		test_texture(dta, x);
		x++;
	}
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
		// printf("DEBUT\n");
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

void	calcul_texture(t_data *dta)
{
	double	wallx;

	if (dta->side == 0)
		wallx = dta->p.pos_y + dta->perpWallDist * dta->rayDirY;
	else
		wallx = dta->p.pos_x + dta->perpWallDist * dta->rayDirX;
	wallx -= floor(wallx);
	dta->tex_x = (int)(wallx * (double)(dta->texwidth));
	if(dta->side == 0 && dta->rayDirX > 0)
		dta->tex_x = dta->texwidth - dta->tex_x - 1;
	if(dta->side == 1 && dta->rayDirY < 0)
		dta->tex_x = dta->texwidth - dta->tex_x - 1;
}
void	test_texture(t_data *dta, int x)
{
	double			step;
	double			texPos;
	int				y;
	unsigned int	color;

	step = 1.0 * dta->texheight / dta->lineHeight;
	texPos = (dta->drawStart - dta->height / 2 + dta->lineHeight / 2) * step;
	y = dta->drawStart;
	while (y <= dta->drawEnd)
	{
		dta->tex_y = (int)texPos & (dta->texheight - 1);
		texPos += step;
		color = choose_texture(dta);
		if(dta->side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(dta, x, y, color);
		y++;
	}
}

int	choose_texture(t_data *dta)
{
	unsigned int	color;

	if (dta->side == 0 && dta->rayDirX < 0)
		color = my_mlx_pixel_get(dta, dta->tex_x, dta->tex_y, 0);
	if (dta->side == 0 && dta->rayDirX > 0)
		color = my_mlx_pixel_get(dta, dta->tex_x, dta->tex_y, 1);
	if (dta->side == 1 && dta->rayDirY < 0)
		color = my_mlx_pixel_get(dta, dta->tex_x, dta->tex_y, 3);
	if (dta->side == 1 && dta->rayDirY > 0)
		color = my_mlx_pixel_get(dta, dta->tex_x, dta->tex_y, 2);
	return (color);
}
