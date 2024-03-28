/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:29:30 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/28 17:30:22 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void noempty(t_data *dta, char *id)
{
	if (id == NULL)
		ft_exit(dta, "there is 2 same id");
}

char	*init_path(t_data *dta, char *tex_path, int nbr)
{
	int		end;
	int		start_path;
	char	*tmp_path;

	start_path = 0;
	while (tex_path[start_path] && (tex_path[start_path] == ' ' || tex_path[start_path] == '\t'))
		start_path++;
	end = start_path + nbr;
	if (tex_path[end] == '\0' || (tex_path[end] != ' ' && tex_path[end] != '\t'))
		ft_exit(dta, "No path on a texture");
	while (tex_path[end] && (tex_path[end] == ' ' || tex_path[end] == '\t'))
		end++;
	start_path = end;
	while (tex_path[end] != '\0')
		end++;
	end--;
	while (tex_path[end] == ' ' || tex_path[end] == '\t')
		end--;
	tmp_path = ft_substr(tex_path, start_path, end - start_path + 1);
	if (tmp_path == NULL)
		ft_exit(dta, "bad path texture");
	return (tmp_path);
}

void verif_color(t_data *dta)
{
	int i;

	i = 0;
	while (dta->texture[4].path[i] != '\0')
	{
		if (!((dta->texture[4].path[i] == ' ' || dta->texture[4].path[i] == '\t' || dta->texture[4].path[i] == ',' ) || (dta->texture[4].path[i] >= '0' && dta->texture[4].path[i] <= '9')))
			ft_exit(dta, "nique bien ta mere\n");
		i++;
	}
	i = 0;
	while (dta->texture[5].path[i] != '\0')
	{
		if (!((dta->texture[5].path[i] == ' ' || dta->texture[5].path[i] == '\t' || dta->texture[5].path[i] == ',' ) || (dta->texture[5].path[i] >= '0' && dta->texture[5].path[i] <= '9')))
			ft_exit(dta, "nique bien ta mere\n");
		i++;
	}
	if (dta->color[0].red == 0 || dta->color[0].green == 0 || dta->color[0].blue == 0 ||
	dta->color[1].red == 0 || dta->color[1].green == 0 || dta->color[1].blue == 0)
		ft_exit(dta, "color pas bon mon copainnn\n");
	if (dta->nbr_comma != 4)
		ft_exit(dta, "pas bon, trop de virgules\n");
	if (dta->color[0].red > 255 || dta->color[0].green > 255 || dta->color[0].blue > 255 ||
	dta->color[1].red > 255 || dta->color[1].green > 255 || dta->color[1].blue > 255)
		ft_exit(dta, "wsh t un ouf a mettre des nombres comme ca gros\n");
}

int init_color(t_data *dta, char *id)
{
	int     i2;
	int     nombre;
	char    *nbr;

	i2 = dta->i_color;
	while (id[i2] >= '0' && id[i2] <= '9')
		i2++;
	nbr = ft_substr(id, dta->i_color, i2 - dta->i_color + 1);
	if (!nbr)
		ft_exit(dta, "pb malloc");
	dta->i_color = i2;
	while (id[dta->i_color] == ' ' || id[dta->i_color] == '\t' || id[dta->i_color] == ',')
	{
		if (id[dta->i_color] == ',')
			dta->nbr_comma++;
		dta->i_color++;
	}
	i2 = dta->i_color;
	if (dta->nbr_comma == 2 || dta->nbr_comma == 4)
	{
		while (id[i2] >= '0' && id[i2] <= '9')
			i2++;
		while (id[i2] != '\0')
		{
			if (!(id[i2] == ' ' || id[i2] == '\t' || id[i2] == ',' ))
				ft_exit(dta, "trop de nombres , RVB\n");
			i2++;
		}
	}
	nombre = ft_atoi(nbr);
	free(nbr);
	return (nombre);
}

int	first_parsing(t_data *dta)
{
	noempty(dta, dta->NO);
	noempty(dta, dta->EA);
	noempty(dta, dta->SO);
	noempty(dta, dta->WE);
	noempty(dta, dta->C);
	noempty(dta, dta->F);
	dta->texture = malloc(sizeof(t_texture) * 6);
	dta->texture[0].path = init_path(dta, dta->NO, 2);
	dta->texture[1].path = init_path(dta, dta->SO, 2);
	dta->texture[2].path = init_path(dta, dta->EA, 2);
	dta->texture[3].path = init_path(dta, dta->WE, 2);
	dta->texture[4].path = init_path(dta, dta->F, 1);
	dta->texture[5].path = init_path(dta, dta->C, 1);
	// printf("dta->texture[0].path : '%s'\n", dta->texture[0].path);
	// printf("dta->texture[1].path : '%s'\n", dta->texture[1].path);
	// printf("dta->texture[2].path : '%s'\n", dta->texture[2].path);
	// printf("dta->texture[3].path : '%s'\n", dta->texture[3].path);
	// printf("dta->texture[4].path : '%s'\n", dta->texture[4].path);
	// printf("dta->texture[5].path : '%s'\n", dta->texture[5].path);
	dta->color[0].red = init_color(dta, dta->texture[4].path);
	dta->color[0].green = init_color(dta, dta->texture[4].path);
	dta->color[0].blue = init_color(dta, dta->texture[4].path);
	// printf("dta->color[0].red : '%d'\n", dta->color[0].red);
	// printf("dta->color[0].green : '%d'\n", dta->color[0].green);
	// printf("dta->color[0].blue : '%d'\n", dta->color[0].blue);
	dta->i_color = 0;
	dta->color[1].red = init_color(dta, dta->texture[5].path);
	dta->color[1].green = init_color(dta, dta->texture[5].path);
	dta->color[1].blue = init_color(dta, dta->texture[5].path);
	// printf("dta->color[1].red : '%d'\n", dta->color[1].red);
	// printf("dta->color[1].green : '%d'\n", dta->color[1].green);
	// printf("dta->color[1].blue : '%d'\n", dta->color[1].blue);
	verif_color(dta);
	return (0);
}
