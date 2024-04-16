/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_before_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:43:20 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/10 16:48:13 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parsing_before_map(t_data *dta, char *file)
{
	gnl_forparsing(dta, file);
	search_real_start(dta);
	search_end_map(dta);
	return ;
}

char	*ft_joinforme(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		str[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	str[i] = '\a';
	str[i + 1] = '\0';
	return (str);
}

char	*ft_strjoinfree2(char *stock, char *tmp)
{
	char	*str;

	str = ft_joinforme(stock, tmp);
	if (stock)
		free(stock);
	return (str);
}

void	gnl_forparsing(t_data *dta, char *file)
{
	int		fd;
	char	*line;
	char	*line2;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY, 0777);
	line = get_next_line(fd);
	line = ft_strjoinfree2(line, "\a");
	while (1)
	{
		i++;
		line2 = get_next_line(fd);
		if (!line2)
			break ;
		line = ft_strjoinfree2(line, line2);
		free(line2);
	}
	close(fd);
	if (line == NULL)
		ft_exit(dta, "line NULL on all_file");
	dta->real_map = ft_split(line, '\a');
	free(line);
	if (i == 0)
		ft_exit(dta, "Nothing in the all_file");
}
