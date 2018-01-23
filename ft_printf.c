/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:00:14 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 13:43:43 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void set_default(t_data *data)
{
	int	i;

	i = 0;
	data->c = '\0';
	while (i < 5)
	{
		(data->f)[i] = '\0';
		i++;
	}
	i = 0;
	while (i < 2)
	{
		(data->fw)[i] = 0;
		(data->p)[i] = 0;
		(data->lm)[i] = '\0';
		i++;
	}
}

static void	ft_printf_help(const char *str, va_list ap, int *count, int i)
{
	t_data	data;

	set_default(&data); //sets data to default values
	while (str[i])
	{
		if (checker(str[i]) == 0) //conversion char
		{
			data.c = str[i++];
			count[1] += process_data(&data, ap); //ret # of char printed
			break ;
		}
		else if (checker(str[i]) == 1) //flag char
			i += set_flag(&data, str[i]);
		else if (ft_isdigit(str[i]) == 1) //min field-width
		{
			(data.fw)[0] = 1;
			(data.fw)[1] = ft_atoi(str + i);
			i += ft_digit_count((data.fw)[1]);
		}
		else if (str[i] == '.') //precision
		{
			(data.p)[0] = 1;
			(data.p)[1] = ft_atoi(str + i + 1);
			i++;
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
		else if (checker(str[i]) == 2) //length modifier char
			i += set_modifier(&data, (char*)(str + i));
		/*else if (str[i] == '%') //'%' char case
		{
			ft_putchar('%');
			i++;
			count[1]++;
			break ;
		}*/
		else //means char doesn't match any flags/convs (might need changes)
			break ;
	}
	count[0] += i + 1;
}

/*
** count[0] = index of str
** count[1] = count of num of chars printed (return value)
*/

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	int			count[2];

	va_start(ap, str);
	count[0] = 0;
	count[1] = 0;
	while (str[count[0]])
	{
		if (str[count[0]] == '%')
			ft_printf_help(str + count[0] + 1, ap, count, 0);
		else
		{
			ft_putchar(str[count[0]++]);
			count[1]++;
		}
	}
	va_end(ap);
	return (count[1]);
}
