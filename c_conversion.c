/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:48:21 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 18:05:50 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(t_data *data, unsigned char c)
{
	int	i;

	i = 1;
	if (flag_check(data->f, '-') == 1)
	{
		ft_putchar(c);
		while ((data->fw)[1] > i++)
			ft_putchar(' ');
	}
	else if (flag_check(data->f, '0') == 1)
	{
		while ((data->fw)[1] > i++)
			ft_putchar('0');
		ft_putchar(c);
	}
	else
	{
		while ((data->fw)[1] > i++)
			ft_putchar(' ');
		ft_putchar(c);
	}
	return ((data->fw)[1]);
}

int			c_conversion(t_data *data, va_list ap)
{
	unsigned char	c;

	if ((data->lm)[0] == 'l' && (data->lm)[1] == '\0')
		return (lc_conversion(data, ap));
	c = (unsigned char)(va_arg(ap, int));
	if ((data->fw)[0] == 1 && (data->fw)[1] > 1)
		return (helper(data, c));
	ft_putchar(c);
	return (1);
}
