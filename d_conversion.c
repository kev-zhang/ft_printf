/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:32:58 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 15:36:39 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	get_data(t_data *data, va_list ap)
{
	short		s;
	signed char	c;

	if ((data->lm)[0] == 'h' && (data->lm)[1] == 'h')
	{
		c = (signed char)va_arg(ap, int);
		return ((long long)c);
	}
	else if ((data->lm)[0] == 'h' && (data->lm)[1] == '\0')
	{
		s = (short)va_arg(ap, int);
		return ((long long)s);
	}
	else if ((data->lm)[0] == 'l' && (data->lm)[1] == '\0')
		return ((long long)(va_arg(ap, long)));
	else if ((data->lm)[0] == 'l' && (data->lm)[1] == 'l')
		return ((long long)(va_arg(ap, long long)));
	else if ((data->lm)[0] == 'j')
		return ((long long)(va_arg(ap, intmax_t)));
	else if ((data->lm)[0] == 'z')
		return ((long long)(va_arg(ap, long)));
	else
		return ((long long)(va_arg(ap, int)));
}

/*
** s is the sign of n: 1 = 0 or positive, 0 = negative
*/

static int			padding_calc(t_data *d, unsigned long long n, int s)
{
	int	digit;
	int	pad;

	digit = 1;
	while (n >= 10)
	{
		digit++;
		n /= 10;
	}
	if ((d->p)[0] == 1 && (d->p)[1] > digit)
		pad = (d->fw)[1] - (d->p)[1];
	else
		pad = (d->fw)[1] - digit;
	if (s == 0 || flag_check(d->f, '+') == 1 || flag_check(d->f, ' ') == 1)
		pad--;
	if (pad < 0)
		pad = 0;
	return (pad);
}

static int			print_nbr(t_data *d, unsigned long long n, int s)
{
	int	ret;

	ret = 0;
	if (s == 0 || flag_check(d->f, '+') == 1 || flag_check(d->f, ' ') == 1)
	{
		if (!(flag_check(d->f, '-') == 1 || flag_check(d->f, '0') == 0))
			ret++;
		else if (s == 0 && ++ret)
			ft_putchar('-');
		else if (flag_check(d->f, '+') == 1 && ++ret)
			ft_putchar('+');
		else if (++ret)
			ft_putchar(' ');
	}
	ret += putnbr_base(n, d->p, 10);
	return (ret);
}

static void			print_pad(t_data *d, int pad, int check)
{
	int		i;
	char	c;

	i = 0;
	if (check == 1 || (d->p)[0] == 1 || flag_check(d->f, '0') == 0)
		c = ' ';
	else
		c = '0';
	while (i < pad)
	{
		ft_putchar(c);
		i++;
	}
}

int					d_conversion(t_data *data, va_list ap)
{
	long long			num;
	unsigned long long	nbr;
	int					pad;
	int					ret;

	num = get_data(data, ap);
	if (num == 0 && (data->p)[0] == 1 && (data->p)[1] == 0)
		return (zero_prec(data));
	pad = 0;
	nbr = (num < 0) ? (unsigned long long)(num * -1) : (unsigned long long)num;
	if ((data->fw)[0] == 1)
		pad = padding_calc(data, nbr, num >= 0);
	if (flag_check(data->f, '-') == 1)
	{
		ret = print_nbr(data, nbr, num >= 0);
		print_pad(data, pad, 1);
	}
	else
	{
		d_conversion_helper(data, num);
		print_pad(data, pad, 0);
		ret = print_nbr(data, nbr, num >= 0);
	}
	return (ret + pad);
}
