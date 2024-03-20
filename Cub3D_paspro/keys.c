/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:00:51 by sboetti           #+#    #+#             */
/*   Updated: 2023/12/19 16:00:51 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	keypress_esc(int key, t_data *dta)
{
	// printf("%d\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(dta->mlx.mlx_ptr, dta->mlx.win_ptr);
		ft_exit_success(dta);
	}
	if (key == 119)//AVANCER
	{
		ft_forward(dta, key);
	}
	if (key == 115)//RECULER//s'il n'y a pas de mur derriere toi
	{
		ft_backward(dta, key);
	}
	if (key == 100)//DROITE //la direction et le plan de la caméra doivent pivoter
	{
		ft_right(dta, key);
	}
	if (key == 97)// GAUCHE //la direction et le plan de la caméra doivent pivoter
	{
		ft_left(dta, key);
	}
	init_raycasting(dta);
	return (0);
}

void	ft_forward(t_data *dta, int key)
{
	printf("forward : %d\n", key);
	if (dta->real_map[(int)(dta->player.pos_x + dta->player.dir_x * dta->player.moveSpeed)][(int)(dta->player.pos_y)] != '1')
		dta->player.pos_x += dta->player.dir_x * dta->player.moveSpeed;
	else if (dta->real_map[(int)(dta->player.pos_x)][(int)(dta->player.pos_y + dta->player.pos_y * dta->player.moveSpeed)] != '1')
		dta->player.pos_y += dta->player.pos_y * dta->player.moveSpeed;
}

void	ft_backward(t_data *dta, int key)
{
	printf("backward : %d\n", key);
	if (dta->real_map[(int)(dta->player.pos_x - dta->player.dir_x * dta->player.moveSpeed)][(int)(dta->player.pos_y)] != '1')
		dta->player.pos_x -= dta->player.dir_x * dta->player.moveSpeed;
	else if (dta->real_map[(int)(dta->player.pos_x)][(int)(dta->player.pos_y - dta->player.pos_y * dta->player.moveSpeed)] != '1')
		dta->player.pos_y -= dta->player.pos_y * dta->player.moveSpeed;
}

void	ft_right(t_data *dta, int key)
{
	printf("right : %d\n", key);
	double oldDirX = dta->player.dir_x;
	dta->player.dir_x = dta->player.dir_x * cos(-(dta->player.rotSpeed)) - dta->player.pos_y * sin(-(dta->player.rotSpeed));
	dta->player.pos_y = oldDirX * sin(-(dta->player.rotSpeed)) + dta->player.pos_y * cos(-(dta->player.rotSpeed));
	double oldPlaneX = dta->player.plane_x;
	dta->player.plane_x = dta->player.plane_x * cos(-(dta->player.rotSpeed)) - dta->player.plane_y * sin(-(dta->player.rotSpeed));
	dta->player.plane_y = oldPlaneX * sin(-(dta->player.rotSpeed)) + dta->player.plane_y * cos(-(dta->player.rotSpeed));
}

void	ft_left(t_data *dta, int key)
{
	printf("left : %d\n", key);
	double oldDirX = dta->player.dir_x;
	dta->player.dir_x = dta->player.dir_x * cos(dta->player.rotSpeed) - dta->player.pos_y * sin(dta->player.rotSpeed);
	dta->player.pos_y = oldDirX * sin(dta->player.rotSpeed) + dta->player.pos_y * cos(dta->player.rotSpeed);
	double oldPlaneX = dta->player.plane_x;
	dta->player.plane_x = dta->player.plane_x * cos(dta->player.rotSpeed) - dta->player.plane_y * sin(dta->player.rotSpeed);
	dta->player.plane_y = oldPlaneX * sin(dta->player.rotSpeed) + dta->player.plane_y * cos(dta->player.rotSpeed);
}