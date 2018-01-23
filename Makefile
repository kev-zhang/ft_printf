# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pzhang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 13:30:29 by pzhang            #+#    #+#              #
#    Updated: 2018/01/22 18:39:59 by pzhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
INCLUDE			= ft_printf.h
SOURCE			= ft_printf.c ft_putchar.c ft_atoi.c set_flag.c checker.c set_modifier.c ft_isdigit.c ft_digit_count.c s_conversion.c ft_putstr.c ft_strlen.c flag_check.c process_data.c ft_putnbr.c ft_strdup.c ls_conversion.c d_conversion.c putnbr_base.c ux_conversion.c o_conversion.c x_cap_conversion.c putnbr_base_cap.c ldou_conversion.c c_conversion.c lc_conversion.c putwchar.c p_conversion.c perc_conversion.c zero_prec.c d_conversion_helper.c empty_str.c none_conversion.c
OFILES			= $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Werror -Wall -Wextra -c $(SOURCE)
	@ar rc $(NAME) $(OFILES)

clean:
	@/bin/rm -f $(OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
