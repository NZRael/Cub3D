/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:29:19 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/21 12:37:15 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

//F 190, 150, 110 
//C 70,		 190,				 255	

typedef struct s_texture
{
	char	*path;
	void	*tex;
	int		width;
	int		height;
}	t_texture;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_p
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	moveSpeed;
	double	rotSpeed;
}	t_p;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_mlx;

typedef struct s_data
{
	t_texture	texture[6];
	t_color		color[2];
	t_p	p;
	t_mlx		mlx;
	int			nbr_n;
	int			nbr_s;
	int			nbr_e;
	int			nbr_w;
	int			start_map;
	char		**map;
	char		**real_map;
	char		*map_str;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*F;
	char		*C;
	int			i_color;
	int			nbr_comma;
	int			width;
	int			height;
	
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double		mapX;
	double		mapY;
	double		deltaDistX;
	double		deltaDistY;
	double		sideDistX;
	double		sideDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
}	t_data;

void	mlx_begin(t_data *dta);

void	ft_check_mapfile(t_data *dta, char *mapfile);
void	check_args(int argc, char **argv, t_data *dta);

void	verif_doublon(t_data *dta);
void	verif_color(t_data *dta);
int		init_color(t_data *dta, char *id);
void	read_map(char *map, t_data *dta);
//int     parsingcar(t_data *dta);
int		structuration(t_data *dta);
int		all_parsing(t_data *dta);
void	ft_exit(t_data *dta, char *str);
void	ft_exit_success(t_data *dta);
int		ft_destroy_wind(int event, t_data *dta);
void	ft_initialisation(t_data *dta);
void	verif_char(t_data *dta, int i, int i2);
int		parsing_map(t_data *dta);

int		keypress_esc(int key, t_data *dta);
void	ft_forward(t_data *dta, int key);
void	ft_backward(t_data *dta, int key);
void	ft_right(t_data *dta, int key);
void	ft_left(t_data *dta, int key);
void	ft_rotate_right(t_data *dta, int key);
void	ft_rotate_left(t_data *dta, int key);

void	test_init_textures(t_data *dta, int i);
void	load_textures(t_data *dta);
void	init_p(t_data *dta);
void	init_raycasting(t_data *dta);
void	calcul_delta(t_data *dta);
void	calcul_side_dest(t_data *dta);
void	perform_dda(t_data *dta);
void	projected_dist(t_data *dta);

void	print_wall(t_data *dta, int x, int color);
int		test_texture(t_data *dta);
void	ft_take_map(t_data *dta);
int		ft_count_take_map(t_data *dta);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif