/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:29:19 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/12 16:54:23 by fleriche         ###   ########.fr       */
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

typedef struct s_data{

    char* map_str;
    char** map;

} t_data;

int	main(int argc, char **argv);
void	check_args(int argc, char **argv, t_data *dta);
void	ft_check_mapfile(t_data *dta, char *mapfile);
void	read_map(char *map, t_data *dta);
void	ft_exit(t_data *dta, char *str);
void	ft_exit_success(t_data *dta);

#endif