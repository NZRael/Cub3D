/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:29:19 by fleriche          #+#    #+#             */
/*   Updated: 2023/12/18 17:09:23 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MiniLibX/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_texture {
	char *path;
} t_texture;

typedef struct s_color {
	int red;
	int green;
	int blue;
} t_color;

typedef struct s_data {
    t_texture	texture[6];
	t_color	color[2];
	int	nbr_n;
    int nbr_s;
    int	nbr_e;
    int nbr_w;
	int 	start_map;
	char	**map;
	char	*map_str;
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *F;
    char    *C;
	int		i_color;
	int		nbr_comma;
	// char	**map_buf;
	// int		map_x;
	// int		map_y;
	// int		nb_collectible;
	// int		nb_exit;
	// int		img_x;
	// int		img_y;
	// int		p_y;
	// int		p_x;
} t_data;

void verif_doublon(t_data *dta);
void verif_color(t_data *dta);
int init_color(t_data *dta, char *id);
void    read_map(char *map, t_data *dta);
//int     parsingcar(t_data *dta);
int     structuration(t_data *dta);
int 	all_parsing(t_data *dta);
void	ft_exit(t_data *dta, char *str);
void	ft_initialisation(t_data *dta);
void verif_char(t_data *dta, int i, int i2);
int parsing_map(t_data *dta);

#endif