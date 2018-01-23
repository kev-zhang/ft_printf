/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:44:38 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/18 15:20:47 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits(unsigned long long num, int base)
{
	int	d;

	d = 1;
	while (num >= (unsigned long long)base)
	{
		d++;
		num /= (unsigned long long)base;
	}
	return (d);
}

static void	putnbr_base_help(unsigned long long n, int base)
{
	if (n / (unsigned long long)base == 0)
	{
		if (base > 10 && n >= 10)
			ft_putchar('a' + (int)(n - 10));
		else
			ft_putchar('0' + (int)n);
	}
	else
	{
		putnbr_base_help(n / (unsigned long long)base, base);
		if (base > 10 && n % (unsigned long long)base >= 10)
			ft_putchar('a' + (int)((n % (unsigned long long)base) - 10));
		else
			ft_putchar('0' + (int)(n % (unsigned long long)base));
	}
}

int			putnbr_base(unsigned long long n, int *p, int base)
{
	int	d;
	int i;

	d = digits(n, base);
	i = 0;
	if (p[0] == 1)
	{
		while (i < p[1] - d)
		{
			ft_putchar('0');
			i++;
		}
	}
	putnbr_base_help(n, base);
	return (i + d);
}
