/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:45:27 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/27 17:28:04 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_exit(t_data *dta, char *str)
{
	(void)dta;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_exit_success(t_data *dta)
{
	(void)dta;
	exit(EXIT_SUCCESS);
}

int	ft_destroy_wind(int event, t_data *dta)
{
	(void)event;
	ft_exit_success(dta);
	return (0);
}
