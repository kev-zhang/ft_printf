/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:00:14 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 18:38:42 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_default(t_data *data)
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

static int	helper(t_data *data, const char *str, int i)
{
	int	ret;

	if (checker(str[i]) == 1)
		return (set_flag(data, str[i]));
	else if (ft_isdigit(str[i]) == 1)
	{
		(data->fw)[0] = 1;
		(data->fw)[1] = ft_atoi(str + i);
		return (ft_digit_count((data->fw)[1]));
	}
	else if (str[i] == '.')
	{
		(data->p)[0] = 1;
		(data->p)[1] = ft_atoi(str + i + 1);
		ret = i + 1;
		while (ft_isdigit(str[ret]) == 1)
			ret++;
		return (ret - i);
	}
	else
		return (set_modifier(data, (char*)(str + i)));
}

static void	ft_printf_help(const char *str, va_list ap, int *count, int i)
{
	t_data	data;

	set_default(&data);
	while (str[i])
	{
		if (checker(str[i]) == 0)
		{
			data.c = str[i++];
			count[1] += process_data(&data, ap);
			break ;
		}
		else if (checker(str[i]) == 1 || ft_isdigit(str[i]) == 1 ||
					str[i] == '.' || checker(str[i]) == 2)
			i += helper(&data, str, i);
		else
		{
			count[1] += none_conversion(&data);
			break ;
		}
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
