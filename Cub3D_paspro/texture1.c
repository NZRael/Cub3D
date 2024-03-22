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

void	test_init_textures(t_data *dta, int i)
{
	int	x;
	int	y;

	if (i < 0 || i >= 6)
		ft_exit(dta, "Index de texture invalide.");
	printf("Loading texture ...\n");
	dta->texture[i].tex = mlx_xpm_file_to_image(dta->mlx.mlx_ptr,
			dta->texture[i].path, &x, &y);
	if (dta->texture[i].tex == NULL)
		ft_exit(dta, "Invalid textures !");
	printf("Texture '%s' is loaded successfully.\n", dta->texture[i].path);
}

void	test_rgb(t_data *dta)
{
	int	x;
	int	y;

	y = 0;
	while (y < dta->height / 2)
	{
		x = 0;
		while (x < dta->width)
			my_mlx_pixel_put(dta, x++, y, create_rgb(dta->color[1].red,
					dta->color[1].green, dta->color[1].blue));
		y++;
	}
	while (y < dta->height)
	{
		x = 0;
		while (x < dta->width)
			my_mlx_pixel_put(dta, x++, y, create_rgb(dta->color[0].red,
					dta->color[0].green, dta->color[0].blue));
		y++;
	}
}

void	load_textures(t_data *dta)
{
	// int	i;
//
	// i = 0;
	// while (i < 4)
	// {
	// 	test_init_textures(dta, i);
	// 	i++;
	// }
	test_rgb(dta);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *dta, int x, int y, int color)
{
	char	*d;

	// if (y < 0 || y >= dta->height || x < 0 || x >= dta->width)
	// 	return ;
	d = dta->mlx.addr + (y * dta->mlx.l_length + x * (dta->mlx.bits_p_pix / 8));
	*(unsigned int *)d = color;
}
