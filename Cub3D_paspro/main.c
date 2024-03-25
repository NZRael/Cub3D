/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:29:16 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/25 12:03:35 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mlx_begin(t_data *dta)
{
	dta->width = 1400;
	dta->height = 700;
	dta->mlx.mlx_ptr = mlx_init();
	dta->mlx.win_ptr = mlx_new_window(dta->mlx.mlx_ptr, dta->width, dta->height, "Cub3D");
	dta->mlx.img = mlx_new_image(dta->mlx.mlx_ptr, dta->width, dta->height);
	dta->mlx.addr = mlx_get_data_addr(dta->mlx.img, &dta->mlx.bits_p_pix, &dta->mlx.l_length,
								&dta->mlx.endian);
	return ;
}

int	main(int argc, char **argv)
{
	t_data	dta;

	check_args(argc, argv, &dta);
	read_map(argv[1], &dta);
	all_parsing(&dta);
/////////////////////////
	ft_take_map(&dta);
	// for (int x = 0; dta.real_map[x] != NULL; x++)
	// 	printf("dta->real_map[%d] = '%s'\n", x, dta.real_map[x]);
/////////////////////////
	mlx_begin(&dta);
	init_p(&dta);
	init_textures(&dta);
	init_raycasting(&dta);

	mlx_hook(dta.mlx.win_ptr, 2, 1L<<0, &keypress_esc, &dta);
	mlx_hook(dta.mlx.win_ptr, 17, 1L<<17, &ft_destroy_wind, NULL);
	mlx_loop(dta.mlx.mlx_ptr);
	return (0);
}
