/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:29:19 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/21 14:08:37 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_texture {
	char *path;
} t_texture;

typedef struct s_color {
	int red;
	int green;
	int blue;
} t_color;

typedef struct s_data{

    char* map_str;
    char** map;
    char** map_cpy;
    // dta->NO;
    // dta->SO;
    // dta->EA;
    // dta->WE;
    // dta->C;
    // dta->F;
    // dta->i_color;
    // dta->nbr_comma;
    // dta->nbr_n;
    // dta->nbr_s;
    // dta->nbr_e;
    // dta->nbr_w
    t_texture	texture[6];
	t_color	color[2];
    int	    nbr_n;
    int     nbr_s;
    int	    nbr_e;
    int     nbr_w;
	int     start_map;
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *F;
    char    *C;
	int		i_color;
	int		nbr_comma;
    int     player_x;
    int     player_y;
    char    payer_letter;
    int     start_map_cpy;
    int     end_map;

} t_data;


int	    main(int argc, char **argv);
void	check_args(int argc, char **argv, t_data *dta);
void	ft_check_mapfile(t_data *dta, char *mapfile);
void	read_map(char *map, t_data *dta);
void	ft_exit(t_data *dta, char *str);
void	ft_exit_success(t_data *dta);
void	ft_initialisation(t_data *dta);
int     all_parsing(t_data *dta);
int     parsing_map(t_data *dta);
void    player_extend(t_data *dta);
void    verif_holes(t_data *dta);

#endif