/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:27:53 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 17:20:01 by pzhang           ###   ########.fr       */
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

static int	helper(t_data *data)
{
	int	pad;

	pad = 0;
	if ((data->fw)[0] == 1 && (data->fw)[1] > 3)
		pad = (data->fw)[1] - 3;
	if (flag_check(data->f, '-') == 1)
	{
		ft_putstr("0x0");
		print_pad(pad);
	}
	else
	{
		print_pad(pad);
		ft_putstr("0x0");
	}
	return (3 + pad);
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
	(data->p)[0] = 0;
	(data->p)[1] = 0;
	(data->lm)[0] = 'l';
	(data->lm)[1] = '\0';
	return (ux_conversion(data, ap, 16));
}
