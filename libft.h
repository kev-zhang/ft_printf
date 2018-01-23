/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:54:49 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 13:36:34 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_digit_count(int num);
int		ft_isdigit(int c);
void	ft_putstr(char const *s);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int n);
char	*ft_strdup(const char *src);

#endif
