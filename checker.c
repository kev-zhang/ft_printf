/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:04:49 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 13:43:29 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** checker fn: checks if char is for conversion, flag, or length modifier
**
** returns:
** -1	= none of the options below
** 0	= conversion (sSpdDioOuUxXcC)
** 1	= flags (#, 0, -, +, (space))
** 2	= length modifier (hh, h, l, ll, j, z)
*/

int	checker(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (0);
	else if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	else if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (2);
	else
		return (-1);
}
