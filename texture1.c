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

void	test_textures(t_data *dta, int i)
{
	int	x;
	int	y;

	if (i < 0 || i >= 6)
		ft_exit(dta, "Indice de texture invalide.");
	printf("PATH TEX : %s\n", dta->texture[i].path);
	dta->texture[i].tex = mlx_xpm_file_to_image(dta->mlx_ptr,
			dta->texture[i].path, &x, &y);
	if (dta->texture[i].tex == NULL)
		ft_exit(dta, "Invalid textures !");
	printf("The texture '%s' is loaded successfully.\n", dta->texture[i].path);
}

void	load_textures(t_data *dta)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		test_textures(dta, i);
		i++;
	}
}
