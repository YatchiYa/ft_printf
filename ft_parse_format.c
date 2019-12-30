/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:49:41 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:28:36 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int			ft_str_length_format(char c, va_list argx)
{
	int			length;
	va_list		args;

	length = 0;
	va_copy(args, argx);
	if (c == 'u')
		length = ft_numlen_u(args);
	else if (c == 'd' || c == 'i')
		length = ft_numlen(args);
	else if (c == 'x' || c == 'X')
		length = ft_hexalen(args);
	else if (c == 'p')
		length = (ft_putadr_len(args));
	else if (c == 'c')
		length = 1;
	else if (c == 's')
		length = ft_strlen_args(args);
	return (length);
}

void		ft_parse_format(char *str, va_list args, int *p, int *size)
{
	int	i;

	i = 0;
	*p = *p + 1;
	str[i] == 'd' ? ft_parse_int(args, size) : 0;
	str[i] == 'i' ? ft_parse_int(args, size) : 0;
	str[i] == 'u' ? ft_parse_uint(args, size) : 0;
	str[i] == 'p' ? ft_parse_ptr(args, size) : 0;
	str[i] == 'c' ? ft_parse_char(args, size) : 0;
	str[i] == 's' ? ft_parse_str(args, size) : 0;
	str[i] == '%' ? ft_putchar('%', size) : 0;
	str[i] == 'x' ? ft_parse_hexa(args, size) : 0;
	str[i] == 'X' ? ft_parse_hexa_m(args, size) : 0;
	str[i] == '0' ? ft_parse_zero(&str[i + 1], args, p, size) : 0;
	str[i] > '0' && str[i] <= '9' ? ft_parse_stars(&str[i], args, p, size) : 0;
	str[i] == '-' ? ft_parse_minus(&str[i + 1], args, p, size) : 0;
	str[i] == '*' ? ft_parse_stars(&str[i], args, p, size) : 0;
	str[i] == '.' ? ft_parse_point(&str[i], args, p, size) : 0;
}
