/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:16:00 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/08 16:58:08 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *dta, int x, int y, int color)
{
	char	*d;

	d = dta->mlx.addr + (y * dta->mlx.l_length + x * (dta->mlx.bits_p_pix / 8));
	*(unsigned int *)d = color;
}

int	my_mlx_pixel_get(t_data *dta, int x, int y, int i)
{
	char	*color;

	color = dta->tex[i].addr + (y * dta->tex[i].l_length \
			+ x * (dta->tex[i].bits / 8));
	return (*(unsigned int *)color);
}
