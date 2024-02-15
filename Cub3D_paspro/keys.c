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

int	keypress_esc(int key, t_data *dta)
{
	//printf("%d\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(dta->mlx_ptr, dta->win_ptr);
		ft_exit_success(dta);
	}
	return (0);
}