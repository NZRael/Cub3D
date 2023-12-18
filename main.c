/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:29:16 by fleriche          #+#    #+#             */
/*   Updated: 2023/12/18 22:53:22 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main()
{
    t_data dta;
    read_map("map.cub", &dta);
    all_parsing(&dta);
    
    dta.mlx_ptr = mlx_init();
    dta.win_ptr = mlx_new_window(dta.mlx_ptr, 1600, 900, "Cub3D");

    mlx_loop(dta.mlx_ptr);
    return(0);
}