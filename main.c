/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:29:16 by fleriche          #+#    #+#             */
/*   Updated: 2023/12/19 17:16:17 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	dta;

	check_args(argc, argv, &dta);
	read_map(argv[1], &dta);
	all_parsing(&dta);
	load_textures(&dta);

	dta.mlx_ptr = mlx_init();
	dta.win_ptr = mlx_new_window(dta.mlx_ptr, 1400, 700, "Cub3D");

	mlx_key_hook(dta.win_ptr, &keypress_esc, &dta);
	mlx_loop(dta.mlx_ptr);
	return (0);
}
