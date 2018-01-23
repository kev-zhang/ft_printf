/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base_cap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:44:44 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/19 16:45:40 by pzhang           ###   ########.fr       */
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

static void	helper(unsigned long long n, int base)
{
	if (n / (unsigned long long)base == 0)
	{
		if (base > 10 && n >= 10)
			ft_putchar('A' + (int)(n - 10));
		else
			ft_putchar('0' + (int)n);
	}
	else
	{
		helper(n / (unsigned long long)base, base);
		if (base > 10 && n % (unsigned long long)base >= 10)
			ft_putchar('A' + (int)((n % (unsigned long long)base) - 10));
		else
			ft_putchar('0' + (int)(n % (unsigned long long)base));
	}
}

int			putnbr_base_cap(unsigned long long n, int *p, int base)
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
	helper(n, base);
	return (i + d);
}
