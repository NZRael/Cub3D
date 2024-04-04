/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:29:19 by fleriche          #+#    #+#             */
/*   Updated: 2024/04/04 15:50:00 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>	

typedef struct s_texture
{
	char	*path;
	void	*tex;
	char	*addr;
	int		bits;
	int		l_length;
	int		endian;
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
	double	move_s;
	double	rot_s;
}	t_p;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_p_pix;
	int			l_length;
	int			endian;
}	t_mlx;

typedef struct s_data
{
	char		**map_cpy;
	char		payer_letter;
	t_texture	*texture;
	t_color		color[2];
	t_p			p;
	t_mlx		mlx;
	int			nbr_n;
	int			nbr_s;
	int			nbr_e;
	int			nbr_w;
	int			start_map;
	int			end_map;
	char		**map;
	char		**real_map;
	char		*map_str;
	char		*no_line;
	char		*so_line;
	char		*we_line;
	char		*ea_line;
	char		*f_line;
	char		*c_line;
	int			player_x;
	int			player_y;
	int			i_color;
	int			nbr_comma;
	int			width;
	int			height;
	int			texwidth;
	int			texheight;
	int			tex_x;
	int			tex_y;

	double		cam_x;
	double		raydir_x;
	double		raydir_y;
	double		map_x;
	double		map_y;
	double		deltadist_x;
	double		deltadist_y;
	double		sidedest_x;
	double		sidedest_y;
	double		perp_wdist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			draw_start;
	int			draw_end;
}	t_data;

void	create_mapcpy(t_data *dta);
void	zero_extend(t_data *dta);
void	mlx_begin(t_data *dta);

void	ft_check_mapfile(t_data *dta, char *mapfile);
void	check_args(int argc, char **argv, t_data *dta);

int		all_parsing(t_data *dta, char *file);
void	ft_initialisation(t_data *dta);
int		structuration(t_data *dta);
int		first_parsing(t_data *dta);
void	parsing_before_map(t_data *dta, char *file);
void	gnl_forparsing(t_data *dta, char *file);
char	*ft_joinforme(char *s1, char *s2);
char	*ft_strjoinfree(char *stock, char *tmp);
char	*ft_strjoinfree2(char *stock, char *tmp);
void	verif_doublon(t_data *dta);
char	*init_path(t_data *dta, char *tex_path, int nbr);
void	verif_color(t_data *dta);
int		init_color(t_data *dta, char *id);
void	read_map(char *map, t_data *dta);
void	ft_free_tab_texture(t_data *dta);
void	ft_free_tab_color(t_data *dta);
void	ft_exit(t_data *dta, char *str);
void	ft_exit_success(t_data *dta);
int		ft_destroy_wind(int event, t_data *dta);
void	verif_char(t_data *dta, int i, int i2);
int		parsing_map(t_data *dta);
void    player_extend(t_data *dta);
void    verif_holes(t_data *dta);

int		keypress(int key, t_data *dta);
void	ft_forward(t_data *dta, int key);
void	ft_backward(t_data *dta, int key);
void	ft_right(t_data *dta, int key);
void	ft_left(t_data *dta, int key);
void	ft_rotate_right(t_data *dta, int key);
void	ft_rotate_left(t_data *dta, int key);

int		create_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		my_mlx_pixel_get(t_data *dta, int x, int y, int i);
void	init_textures(t_data *dta);
void	init_texture(t_data *dta, int i);
void	print_fc(t_data *dta, int x);
void	init_p(t_data *dta);
void	init_player(t_data *dta);
void	init_direction_w(t_data *dta);
void	init_direction_e(t_data *dta);
void	init_direction_s(t_data *dta);
void    init_direction_n(t_data *dta);
void	init_raycasting(t_data *dta);
void	img_renderer(t_data *dta);
void	calcul_delta(t_data *dta);
void	calcul_side_dest(t_data *dta);
void	perform_dda(t_data *dta);
void	projected_dist(t_data *dta);
void	test_texture(t_data *dta, int x);

void	calcul_texture(t_data *dta);
int		choose_texture(t_data *dta);
int		test_colors(t_data *dta);
void	ft_take_map(t_data *dta);
int		ft_count_take_map(t_data *dta);

#endif