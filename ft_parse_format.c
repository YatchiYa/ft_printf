/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:49:41 by yarab             #+#    #+#             */
/*   Updated: 2020/01/08 10:15:54 by yarab            ###   ########.fr       */
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

void		ff(char *str, va_list args, int *p, int *size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j] == '0')
	{
		j++;
		if (str[j] == '-')
		{
			ft_parse_minus(&str[j + 1], args, p, size);
			break ;
		}
	}
	if (str[j] == '-')
		*p = *p + j;
	else if (str[j] != '-')
		if (str[i] == '0')
			ft_parse_zero(&str[i + 1], args, p, size);
}

void		ft_parse_format(char *str, va_list args, int *p, int *size)
{
	int i;

	i = 0;
	while (str[i] &&
		(ft_is_flags(str[i]) ||
			(str[i] >= '0' && str[i] <= '9')))
	{
		i++;
	}
	if (ft_is_type(str[i]) == 1)
	{
		ft_parse_formatx(str, args, p, size);
	}
	else
	{
		*p = *p + 1;
		ft_putchar('%', size);
		ft_putchar(str[0], size);
	}
}

void		ft_parse_formatx(char *str, va_list args, int *p, int *size)
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
	str[i] == '-' ? ft_parse_minus(&str[i + 1], args, p, size) : 0;
	str[i] == '*' ? ft_parse_stars(&str[i], args, p, size) : 0;
	str[i] == '.' ? ft_parse_point(&str[i], args, p, size) : 0;
	str[i] > '0' && str[i] <= '9' ? ft_parse_digits(&str[i], args, p, size) : 0;
	ff(str, args, p, size);
}
