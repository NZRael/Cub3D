/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:48:17 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/04 22:41:16 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned long n, char *base, int *count)
{
	unsigned int	size;

	size = ft_strlen_ptf(base);
	if (n >= size)
	{
		ft_puthex(n / size, base, count);
		ft_puthex(n % size, base, count);
	}
	else
		ft_putchar_ptf(base[n], count);
}

static void	ft_putadress(size_t arg, int *count)
{
	ft_putstr_ptf("0x", count);
	ft_puthex(arg, "0123456789abcdef", count);
}

void	ft_arguments(char str, va_list arg, int *count)
{
	char	*vaa;

	if (str == 'c')
		ft_putchar_ptf(va_arg(arg, int), count);
	else if (str == 's')
	{
		vaa = va_arg(arg, char *);
		if (!vaa)
			ft_putstr_ptf("(null)", count);
		else
			ft_putstr_ptf(vaa, count);
	}
	else if (str == 'p')
		ft_putadress(va_arg(arg, size_t), count);
	else if (str == 'i' || str == 'd')
		ft_putnbr_ptf(va_arg(arg, int), count);
	else if (str == 'u')
		ft_putnbr_ptf_u(va_arg(arg, unsigned int), count);
	else if (str == 'x')
		ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef", count);
	else if (str == 'X')
		ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF", count);
	else if (str == '%')
		ft_putchar_ptf('%', count);
}
