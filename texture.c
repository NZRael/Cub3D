/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:22:34 by sboetti           #+#    #+#             */
/*   Updated: 2023/12/19 16:22:34 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_textures(t_data *dta)
{
	int	i;

	i = -1;
	while (++i < 4)
		init_texture(dta, i);
}

void	init_texture(t_data *dta, int i)
{
	int	x;
	int	y;

	if (i < 0 || i >= 6)
		ft_exit(dta, "Index de texture invalide.");
	printf("Loading texture '%s'...\n", dta->tex[i].path);
	dta->tex[i].tex = mlx_xpm_file_to_image(dta->mlx.mlx_ptr, \
			dta->tex[i].path, &x, &y);
	if (dta->tex[i].tex == NULL)
		ft_exit(dta, "Invalid textures !");
	printf("Texture '%s' is loaded successfully.\n", dta->tex[i].path);
	dta->tex[i].addr = mlx_get_data_addr(dta->tex[i].tex, \
			&dta->tex[i].bits, &dta->tex[i].l_length, \
			&dta->tex[i].endian);
}

void	print_fc(t_data *dta, int x)
{
	int	y;

	y = 0;
	while (y < dta->draw_start)
	{
		my_mlx_pixel_put(dta, x, y, create_rgb(dta->color[1].r, \
				dta->color[1].g, dta->color[1].b));
		y++;
	}
	y = dta->draw_end;
	while (y < dta->height)
	{
		my_mlx_pixel_put(dta, x, y, create_rgb(dta->color[0].r, \
				dta->color[0].g, dta->color[0].b));
		y++;
	}
	return ;
}
