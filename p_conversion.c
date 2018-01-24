/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:27:53 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/24 14:06:48 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_pad(int pad)
{
	while (pad > 0)
	{
		ft_putchar(' ');
		pad--;
	}
}

static int	print_zero(int *p)
{
	int i;

	i = 0;
	ft_putstr("0x");
	if (p[0] == 1)
	{
		while (i < p[1])
		{
			ft_putchar('0');
			i++;
		}
	}
	else
	{
		ft_putchar('0');
		i++;
	}
	return (2 + i);
}

static int	helper(t_data *data)
{
	int	pad;
	int	ret;

	pad = 0;
	if ((data->fw)[0] == 1 && (data->fw)[1] > 3)
		pad = (data->fw)[1] - 3;
	if (flag_check(data->f, '-') == 1)
	{
		ret = print_zero(data->p);
		print_pad(pad);
	}
	else
	{
		print_pad(pad);
		ret = print_zero(data->p);
	}
	return (ret + pad);
}

int			p_conversion(t_data *data, va_list ap)
{
	va_list			temp;
	unsigned long	n;

	va_copy(temp, ap);
	n = va_arg(temp, unsigned long);
	if (n == 0)
	{
		n = va_arg(ap, unsigned long);
		va_end(temp);
		return (helper(data));
	}
	set_flag(data, '#');
	(data->lm)[0] = 'l';
	(data->lm)[1] = '\0';
	return (ux_conversion(data, ap, 16));
}
