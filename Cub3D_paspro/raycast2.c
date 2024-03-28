/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:58:44 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/28 14:45:35 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_renderer(t_data *dta)
{
	mlx_destroy_image(dta->mlx.mlx_ptr, dta->mlx.img);
	dta->mlx.img = mlx_new_image(dta->mlx.mlx_ptr, dta->width, dta->height);
	dta->mlx.addr = mlx_get_data_addr(dta->mlx.img, &dta->mlx.bits_p_pix, \
			&dta->mlx.l_length, &dta->mlx.endian);
	init_raycasting(dta);
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
	mlx_put_image_to_window(dta->mlx.mlx_ptr, dta->mlx.win, dta->mlx.img, 0, 0);
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
	if (dta->side == 0 && dta->rayDirX > 0)
		dta->tex_x = dta->texwidth - dta->tex_x - 1;
	if (dta->side == 1 && dta->rayDirY < 0)
		dta->tex_x = dta->texwidth - dta->tex_x - 1;
}

void	test_texture(t_data *dta, int x)
{
	double			step;
	double			texpos;
	int				y;
	unsigned int	color;

	step = 1.0 * dta->texheight / dta->lineHeight;
	texpos = (dta->drawStart - dta->height / 2 + dta->lineHeight / 2) * step;
	y = dta->drawStart;
	while (y <= dta->drawEnd)
	{
		dta->tex_y = (int)texpos & (dta->texheight - 1);
		texpos += step;
		color = choose_texture(dta);
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
