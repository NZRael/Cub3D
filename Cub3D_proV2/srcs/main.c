/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:45:25 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/20 14:53:24 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	main(int argc, char **argv)
{
	t_data	dta;

	check_args(argc, argv, &dta);
	read_map(argv[1], &dta);
	all_parsing(&dta);

	// dta.mlx_ptr = mlx_init();
	// dta.win_ptr = mlx_new_window(dta.mlx_ptr, 1400, 700, "Cub3D");

	// load_textures(&dta);

	// mlx_key_hook(dta.win_ptr, &keypress_esc, &dta);
	// mlx_loop(dta.mlx_ptr);
	return (0);
}