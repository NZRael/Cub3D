/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:47:31 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/27 17:23:39 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *s, int c);
void	ft_bzero_gnl(char *sbase, size_t n);
char	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strjoin_gnl(char *s1, char *buff);
char	*ft_getline(char *sbase);
char	*ft_newsbase(char *sbase);

#endif
