/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:35:15 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/04 22:41:06 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_ptf(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_ptf(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr_ptf(char *s, int *count)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_ptf(s[i], count);
		i++;
	}
}

void	ft_putnbr_ptf(int n, int *count)
{
	if (n == -2147483648)
		ft_putstr_ptf("-2147483648", count);
	else if (n < 0)
	{
		ft_putchar_ptf('-', count);
		ft_putnbr_ptf(n * -1, count);
	}
	else if (n > 9)
	{
		ft_putnbr_ptf(n / 10, count);
		ft_putnbr_ptf(n % 10, count);
	}
	else
		ft_putchar_ptf('0' + n, count);
}

void	ft_putnbr_ptf_u(unsigned int n, int *count)
{
	if (n < 0)
	{
		ft_putchar_ptf('-', count);
		ft_putnbr_ptf(n * -1, count);
	}
	else if (n > 9)
	{
		ft_putnbr_ptf(n / 10, count);
		ft_putnbr_ptf(n % 10, count);
	}
	else
		ft_putchar_ptf('0' + n, count);
}
