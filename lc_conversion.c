/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:41:24 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 18:03:38 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(t_data *data, wchar_t c)
{
	int	i;

	i = 1;
	if (flag_check(data->f, '-') == 1)
	{
		putwchar(c);
		while ((data->fw)[1] > i++)
			ft_putchar(' ');
	}
	else if (flag_check(data->f, '0') == 1)
	{
		while ((data->fw)[1] > i++)
			ft_putchar('0');
		putwchar(c);
	}
	else
	{
		while ((data->fw)[1] > i++)
			ft_putchar(' ');
		putwchar(c);
	}
	return ((data->fw)[1]);
}

int			lc_conversion(t_data *data, va_list ap)
{
	wchar_t	c;

	c = (wchar_t)va_arg(ap, int);
	if ((data->fw)[0] == 1 && (data->fw)[1] > 1)
		return (helper(data, c));
	putwchar(c);
	return (1);
}
