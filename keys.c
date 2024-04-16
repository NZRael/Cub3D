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

int	keypress(int key, t_data *dta)
{
	if (key == 65307)
	{
		mlx_destroy_window(dta->mlx.mlx_ptr, dta->mlx.win);
		ft_exit_success(dta);
	}
	if (key == 119)
		ft_forward(dta, key);
	if (key == 115)
		ft_backward(dta, key);
	if (key == 100)
		ft_right(dta, key);
	if (key == 97)
		ft_left(dta, key);
	if (key == 65363)
		ft_rotate_right(dta, key);
	if (key == 65361)
		ft_rotate_left(dta, key);
	return (0);
}

// printf("forward : %d\n", key);
void	ft_forward(t_data *dta, int key)
{
	(void) key;
	if (dta->real_map[(int)(dta->p.pos_x + dta->p.dir_x * dta->p.move_s)] \
			[(int)(dta->p.pos_y)] != '1')
		dta->p.pos_x += dta->p.dir_x * dta->p.move_s;
	if (dta->real_map[(int)(dta->p.pos_x)] \
			[(int)(dta->p.pos_y + dta->p.dir_y * dta->p.move_s)] != '1')
		dta->p.pos_y += dta->p.dir_y * dta->p.move_s;
	img_renderer(dta);
}

	// printf("backward : %d\n", key);
void	ft_backward(t_data *dta, int key)
{
	(void) key;
	if (dta->real_map[(int)(dta->p.pos_x - dta->p.dir_x * dta->p.move_s)] \
			[(int)(dta->p.pos_y)] != '1')
		dta->p.pos_x -= dta->p.dir_x * dta->p.move_s;
	if (dta->real_map[(int)(dta->p.pos_x)] \
			[(int)(dta->p.pos_y - dta->p.dir_y * dta->p.move_s)] != '1')
		dta->p.pos_y -= dta->p.dir_y * dta->p.move_s;
	img_renderer(dta);
}
