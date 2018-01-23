/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 21:47:01 by pzhang            #+#    #+#             */
/*   Updated: 2017/11/30 19:56:31 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		n;

	n = 0;
	while (src[n])
	{
		n++;
	}
	str = (char*)malloc((sizeof(*str)) * (n + 1));
	if (str)
	{
		n = 0;
		while (src[n])
		{
			str[n] = src[n];
			n++;
		}
		str[n] = '\0';
		return (str);
	}
	return (NULL);
}
