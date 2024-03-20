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

void	test_rgb0(t_data *dta, int i)
{
	// printf("Couleur %d : Rouge = %d, Vert = %d, Bleu = %d\n", i, dta->color[i].red, dta->color[i].green, dta->color[i].blue);
	int	win_width;
	int	win_height;
	int	x;
	int	y;
	int	mlx_color;

	win_width = 1400;
	win_height = 700;
	y = win_height / 2;
	while (y < win_height)
	{
		x = 0;
		while (x < win_width)
		{
			mlx_color = (dta->color[i].red << 16) | (dta->color[i].green << 8) | dta->color[i].blue;
			my_mlx_pixel_put(dta, x, y, mlx_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(dta->mlx.mlx_ptr, dta->mlx.win_ptr, dta->mlx.img, 0, 0);
}

void	test_rgb1(t_data *dta, int i)
{
	// printf("Couleur %d : Rouge = %d, Vert = %d, Bleu = %d\n", i, dta->color[i].red, dta->color[i].green, dta->color[i].blue);
	int	win_width;
	int	win_height;
	int	x;
	int	y;
	int	mlx_color;

	win_width = 1400;
	win_height = 700;
	y = 0;
	while (y < win_height / 2)
	{
		x = 0;
		while (x < win_width)
		{
			mlx_color = (dta->color[i].red << 16) | (dta->color[i].green << 8) | dta->color[i].blue;
			my_mlx_pixel_put(dta, x, y, mlx_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(dta->mlx.mlx_ptr, dta->mlx.win_ptr, dta->mlx.img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y >= data->height || x < 0 || x >= data->width)
		return ;
	dst = data->mlx.addr + (y * data->mlx.line_length + x * (data->mlx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	load_textures(t_data *dta)
{
	// int	i;

	// i = 0;
	// while (i < 4)
	// {
	// 	test_init_textures(dta, i);
	// 	i++;
	// }
	test_rgb0(dta, 0);
	test_rgb1(dta, 1);
}
