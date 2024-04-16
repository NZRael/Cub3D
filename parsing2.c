/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:29:30 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/10 16:35:20 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	noempty(t_data *dta, char *id)
{
	if (id == NULL)
		ft_exit(dta, "There is two same id or one id is missing in the file.");
}

char	*init_path(t_data *dta, char *tex_path, int nbr)
{
	int		end;
	int		start_path;
	char	*tmp_path;

	start_path = 0;
	while (tex_path[start_path] && (tex_path[start_path] == ' ' \
			|| tex_path[start_path] == '\t'))
		start_path++;
	end = start_path + nbr;
	if (tex_path[end] == '\0' || (tex_path[end] != ' ' \
			&& tex_path[end] != '\t'))
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
		ft_exit(dta, "Bad path texture");
	return (tmp_path);
}

void	verif_color(t_data *d)
{
	int	i;

	i = -1;
	while (d->tex[4].path[++i] != '\0')
	{
		if (!((d->tex[4].path[i] == ' ' || d->tex[4].path[i] == '\t'
					|| d->tex[4].path[i] == ',' ) || (d->tex[4].path[i] >= '0'
					&& d->tex[4].path[i] <= '9')))
			ft_exit(d, "Color path invalid\n");
	}
	i = -1;
	while (d->tex[5].path[++i] != '\0')
	{
		if (!((d->tex[5].path[i] == ' ' || d->tex[5].path[i] == '\t'
					|| d->tex[5].path[i] == ',' ) || (d->tex[5].path[i] >= '0'
					&& d->tex[5].path[i] <= '9')))
			ft_exit(d, "Color path invalid\n");
	}
	if (d->color[0].r < 0 || d->color[0].g < 0 || d->color[0].b < 0
		|| d->color[1].r < 0 || d->color[1].g < 0 || d->color[1].b < 0
		|| d->color[0].r > 255 || d->color[0].g > 255 || d->color[0].b > 255
		|| d->color[1].r > 255 || d->color[1].g > 255 || d->color[1].b > 255)
		ft_exit(d, "Color out of range\n");
	if (d->nbr_comma != 4)
		ft_exit(d, "Commas error\n");
}

int	first_parsing(t_data *dta)
{
	noempty(dta, dta->no_line);
	noempty(dta, dta->ea_line);
	noempty(dta, dta->so_line);
	noempty(dta, dta->we_line);
	noempty(dta, dta->c_line);
	noempty(dta, dta->f_line);
	dta->tex = malloc(sizeof(t_texture) * 6);
	dta->tex[0].path = init_path(dta, dta->no_line, 2);
	dta->tex[1].path = init_path(dta, dta->so_line, 2);
	dta->tex[2].path = init_path(dta, dta->ea_line, 2);
	dta->tex[3].path = init_path(dta, dta->we_line, 2);
	dta->tex[4].path = init_path(dta, dta->f_line, 1);
	dta->tex[5].path = init_path(dta, dta->c_line, 1);
	dta->color[0].r = init_color(dta, dta->tex[4].path);
	dta->color[0].g = init_color(dta, dta->tex[4].path);
	dta->color[0].b = init_color(dta, dta->tex[4].path);
	dta->i_color = 0;
	dta->color[1].r = init_color(dta, dta->tex[5].path);
	dta->color[1].g = init_color(dta, dta->tex[5].path);
	dta->color[1].b = init_color(dta, dta->tex[5].path);
	verif_color(dta);
	return (0);
}
