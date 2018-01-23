/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:04:48 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 16:23:23 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pad_calc(t_data *data)
{
	int	pad;

	pad = 0;
	if ((data->fw)[0] == 1)
	{
		if ((data->p)[0] == 1)
			pad = (data->fw)[1] - ((data->p)[1] < 6 ? (data->p)[1] : 6);
		else
			pad = (data->fw)[1] - 6;
	}
	if (pad < 0)
		pad = 0;
	return (pad);
}

static int	print_null(char *n, int *p)
{
	int	i;

	if (p[0] == 1)
	{
		i = 0;
		while (i < p[1])
		{
			ft_putchar(n[i]);
			i++;
		}
		return (i);
	}
	ft_putstr(n);
	return (6);
}

static void	print_pad(int pad, char c)
{
	while (pad > 0)
	{
		ft_putchar(c);
		pad--;
	}
}

int			empty_str(t_data *data, char *n)
{
	int	pad;
	int	ret;

	pad = pad_calc(data);
	if (flag_check(data->f, '-') == 1)
	{
		ret = print_null(n, data->p);
		print_pad(pad, ' ');
	}
	else if (flag_check(data->f, '0') == 1)
	{
		print_pad(pad, '0');
		ret = print_null(n, data->p);
	}
	else
	{
		print_pad(pad, ' ');
		ret = print_null(n, data->p);
	}
	return (ret + pad);
}
