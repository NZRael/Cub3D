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
		ft_forward(dta, key);
	if (key == 115)//RECULER//s'il n'y a pas de mur derriere toi
		ft_backward(dta, key);
	if (key == 100)//DROITE
		ft_right(dta, key);
	if (key == 97)//GAUCHE 
		ft_left(dta, key);
	if (key == 65363)//ROTATE DROITE //la direction et le plan de la caméra doivent pivoter
		ft_rotate_right(dta, key);
	if (key == 65361)//ROTATE GAUCHE //la direction et le plan de la caméra doivent pivoter
		ft_rotate_left(dta, key);
	init_raycasting(dta);
	return (0);
}

void	ft_forward(t_data *dta, int key)
{
	// printf("forward : %d\n", key);
	(void) key;
	if (dta->real_map[(int)(dta->p.pos_x + dta->p.dir_x * dta->p.moveSpeed)][(int)(dta->p.pos_y)] != '1')
		dta->p.pos_x += dta->p.dir_x * dta->p.moveSpeed;
	if (dta->real_map[(int)(dta->p.pos_x)][(int)(dta->p.pos_y + dta->p.dir_y * dta->p.moveSpeed)] != '1')
		dta->p.pos_y += dta->p.dir_y * dta->p.moveSpeed;
}

void	ft_backward(t_data *dta, int key)
{
	// printf("backward : %d\n", key);
	(void) key;
	if (dta->real_map[(int)(dta->p.pos_x - dta->p.dir_x * dta->p.moveSpeed)][(int)(dta->p.pos_y)] != '1')
		dta->p.pos_x -= dta->p.dir_x * dta->p.moveSpeed;
	if (dta->real_map[(int)(dta->p.pos_x)][(int)(dta->p.pos_y - dta->p.dir_y * dta->p.moveSpeed)] != '1')
		dta->p.pos_y -= dta->p.dir_y * dta->p.moveSpeed;
}

void	ft_right(t_data *dta, int key)
{
	(void) key;
	if (dta->real_map[(int)(dta->p.pos_x + dta->p.dir_y *
				(dta->p.moveSpeed * 2))][(int)dta->p.pos_y] != '1')
		dta->p.pos_x += dta->p.dir_y * dta->p.moveSpeed;
	if (dta->real_map[(int)dta->p.pos_x][(int)(dta->p.pos_y -
				dta->p.dir_x *
				(dta->p.moveSpeed * 2))] != '1')
		dta->p.pos_y -= dta->p.dir_x * dta->p.moveSpeed;
}

void	ft_left(t_data *dta, int key)
{
	(void) key;
	if (dta->real_map[(int)(dta->p.pos_x - dta->p.dir_y *
				(dta->p.moveSpeed * 2))][(int)dta->p.pos_y] != '1')
		dta->p.pos_x -= dta->p.dir_y * dta->p.moveSpeed;
	if (dta->real_map[(int)dta->p.pos_x][(int)(dta->p.pos_y +
				dta->p.dir_x *
				(dta->p.moveSpeed * 2))] != '1')
		dta->p.pos_y += dta->p.dir_x * dta->p.moveSpeed;
}

void	ft_rotate_right(t_data *dta, int key)
{
	// printf("right : %d\n", key);
	(void) key;
	double oldDirX;
	double oldPlaneX;

	oldDirX = dta->p.dir_x;
	dta->p.dir_x = dta->p.dir_x * cos(-(dta->p.rotSpeed)) - dta->p.dir_y * sin(-(dta->p.rotSpeed));
	dta->p.dir_y = oldDirX * sin(-(dta->p.rotSpeed)) + dta->p.dir_y * cos(-(dta->p.rotSpeed));
	oldPlaneX = dta->p.plane_x;
	dta->p.plane_x = dta->p.plane_x * cos(-(dta->p.rotSpeed)) - dta->p.plane_y * sin(-(dta->p.rotSpeed));
	dta->p.plane_y = oldPlaneX * sin(-(dta->p.rotSpeed)) + dta->p.plane_y * cos(-(dta->p.rotSpeed));
}

void	ft_rotate_left(t_data *dta, int key)
{
	// printf("left : %d\n", key);
	(void) key;
	double oldDirX;
	double oldPlaneX;

	oldDirX = dta->p.dir_x;
	dta->p.dir_x = dta->p.dir_x * cos(dta->p.rotSpeed) - dta->p.dir_y * sin(dta->p.rotSpeed);
	dta->p.dir_y = oldDirX * sin(dta->p.rotSpeed) + dta->p.dir_y * cos(dta->p.rotSpeed);
	oldPlaneX = dta->p.plane_x;
	dta->p.plane_x = dta->p.plane_x * cos(dta->p.rotSpeed) - dta->p.plane_y * sin(dta->p.rotSpeed);
	dta->p.plane_y = oldPlaneX * sin(dta->p.rotSpeed) + dta->p.plane_y * cos(dta->p.rotSpeed);
}