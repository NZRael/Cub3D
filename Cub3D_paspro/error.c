/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:45:27 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/27 14:45:13 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_tab_texture(t_data *dta)
{
	int	i;

	i = 0;
	if (dta->texture)
	{
		while (dta->texture[i].path != NULL)
		{
			free(dta->texture[i].path);
			i++;
		}
		free(dta->texture);
	}
	return ;
}

void	ft_free_tab_color(t_data *dta)
{
	if (dta->color)
	{
		if (dta->color[0] != NULL)
			free(dta->color[0]);
		if (dta->color[1] != NULL)
			free(dta->color[1]);
		free(dta->color);
	}
	return ;
}

void	ft_exit(t_data *dta, char *str)
{
	ft_free_tab_texture(dta);
	ft_free_tab_color(dta);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_exit_success(t_data *dta)
{
	ft_free_tab_texture(dta);
	ft_free_tab_color(dta);
	exit(EXIT_SUCCESS);
}

int	ft_destroy_wind(int event, t_data *dta)
{
	(void)event;
	ft_exit_success(dta);
	return (0);
}
