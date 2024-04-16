/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_left_and_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:31:34 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/29 11:03:35 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// printf("right : %d\n", key);
void	ft_right(t_data *dta, int key)
{
	(void) key;
	if (dta->real_map[(int)(dta->p.pos_x + dta->p.dir_y \
			* (dta->p.move_s * 2))][(int)dta->p.pos_y] != '1')
		dta->p.pos_x += dta->p.dir_y * dta->p.move_s;
	if (dta->real_map[(int)dta->p.pos_x][(int)(dta->p.pos_y \
		- dta->p.dir_x * (dta->p.move_s * 2))] != '1')
		dta->p.pos_y -= dta->p.dir_x * dta->p.move_s;
	img_renderer(dta);
}

// printf("left : %d\n", key);
void	ft_left(t_data *dta, int key)
{
	if (dta->real_map[(int)(dta->p.pos_x - dta->p.dir_y \
			* (dta->p.move_s * 2))][(int)dta->p.pos_y] != '1')
		dta->p.pos_x -= dta->p.dir_y * dta->p.move_s;
	if (dta->real_map[(int)dta->p.pos_x][(int)(dta->p.pos_y \
		+ dta->p.dir_x * (dta->p.move_s * 2))] != '1')
		dta->p.pos_y += dta->p.dir_x * dta->p.move_s;
	img_renderer(dta);
	(void) key;
}

	// printf("right : %d\n", key);
void	ft_rotate_right(t_data *dta, int key)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = dta->p.dir_x;
	dta->p.dir_x = dta->p.dir_x * cos(-(dta->p.rot_s)) \
		- dta->p.dir_y * sin(-(dta->p.rot_s));
	dta->p.dir_y = old_dir_x * sin(-(dta->p.rot_s)) \
		+ dta->p.dir_y * cos(-(dta->p.rot_s));
	old_plane_x = dta->p.plane_x;
	dta->p.plane_x = dta->p.plane_x * cos(-(dta->p.rot_s)) \
		- dta->p.plane_y * sin(-(dta->p.rot_s));
	dta->p.plane_y = old_plane_x * sin(-(dta->p.rot_s)) \
		+ dta->p.plane_y * cos(-(dta->p.rot_s));
	img_renderer(dta);
	(void) key;
}

	// printf("left : %d\n", key);
void	ft_rotate_left(t_data *dta, int key)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = dta->p.dir_x;
	dta->p.dir_x = dta->p.dir_x * cos(dta->p.rot_s) \
		- dta->p.dir_y * sin(dta->p.rot_s);
	dta->p.dir_y = old_dir_x * sin(dta->p.rot_s) \
		+ dta->p.dir_y * cos(dta->p.rot_s);
	old_plane_x = dta->p.plane_x;
	dta->p.plane_x = dta->p.plane_x * cos(dta->p.rot_s) \
		- dta->p.plane_y * sin(dta->p.rot_s);
	dta->p.plane_y = old_plane_x * sin(dta->p.rot_s) \
		+ dta->p.plane_y * cos(dta->p.rot_s);
	img_renderer(dta);
	(void) key;
}
