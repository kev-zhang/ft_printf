/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_cap_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:43:50 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 18:05:30 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	get_data(char *lm, va_list ap)
{
	unsigned short	s;
	unsigned char	c;

	if (lm[0] == 'h' && lm[1] == 'h')
	{
		c = (unsigned char)va_arg(ap, unsigned int);
		return ((unsigned long long)c);
	}
	else if (lm[0] == 'h' && lm[1] == '\0')
	{
		s = (unsigned short)va_arg(ap, unsigned int);
		return ((unsigned long long)s);
	}
	else if (lm[0] == 'l' && lm[1] == '\0')
		return ((unsigned long long)(va_arg(ap, unsigned long)));
	else if (lm[0] == 'l' && lm[1] == 'l')
		return ((unsigned long long)(va_arg(ap, unsigned long long)));
	else if (lm[0] == 'j')
		return ((unsigned long long)(va_arg(ap, uintmax_t)));
	else if (lm[0] == 'z')
		return ((unsigned long long)(va_arg(ap, size_t)));
	else
		return ((unsigned long long)(va_arg(ap, unsigned int)));
}

static int					pad_calc(t_data *d, unsigned long long n)
{
	int					digit;
	int					pad;
	unsigned long long	temp;

	digit = 1;
	temp = n;
	while (n >= 16)
	{
		digit++;
		n /= 16;
	}
	if ((d->p)[0] == 1 && (d->p)[1] > digit)
		pad = (d->fw)[1] - (d->p)[1];
	else
		pad = (d->fw)[1] - digit;
	if (temp != 0 && flag_check(d->f, '#') == 1)
		pad -= 2;
	if (pad < 0)
		pad = 0;
	return (pad);
}

static int					print_nbr(t_data *d, unsigned long long n)
{
	int	ret;

	ret = 0;
	if (n != 0 && flag_check(d->f, '#') == 1)
	{
		ret += 2;
		if ((d->p)[0] == 1 || flag_check(d->f, '-') == 1 ||
				flag_check(d->f, '0') == 0)
			ft_putstr("0X");
	}
	ret += putnbr_base_cap(n, d->p, 16);
	return (ret);
}

static void					print_pad(t_data *d, int pad, int check)
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

int							x_cap_conversion(t_data *data, va_list ap)
{
	unsigned long long	num;
	int					pad;
	int					ret;

	num = get_data(data->lm, ap);
	if (num == 0 && (data->p)[0] == 1 && (data->p)[1] == 0)
		return (zero_prec(data));
	pad = 0;
	if ((data->fw)[0] == 1)
		pad = pad_calc(data, num);
	if (flag_check(data->f, '-') == 1)
	{
		ret = print_nbr(data, num);
		print_pad(data, pad, 1);
	}
	else
	{
		if (flag_check(data->f, '0') == 1 && (data->p)[0] == 0 &&
				flag_check(data->f, '#') == 1 && num != 0)
			ft_putstr("0X");
		print_pad(data, pad, 0);
		ret = print_nbr(data, num);
	}
	return (ret + pad);
}
