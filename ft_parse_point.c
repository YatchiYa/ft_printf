/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:57:58 by yarab             #+#    #+#             */
/*   Updated: 2020/01/10 11:57:22 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"


void	ft_point_parsing_id_extends_2(t_flags flags, int *size)
{
	if (flags.precision < 0)
		ft_putchar('0', size);
	else if (flags.precision == -1)
	{
		ft_print_elem(flags.width, 1, ' ', size);
		ft_putchar('0', size);
	}
	else
	{
		ft_print_elem(flags.width, flags.precision, ' ', size);
		ft_print_elem(flags.precision, 0, '0', size);
	}
}

int	ft_point_parsing_id_extends(t_flags flags, int number, int *size, int n)
{
	if (number < 0)
	{
		ft_print_elem(flags.width,
				flags.precision > n ? flags.precision + 1 : n + 1,
				' ', size);
		ft_putchar('-', size);
		number = number * -1;
		ft_print_elem(flags.precision, n, '0', size);
	}
	else
	{
		ft_print_elem(flags.width, flags.precision > n ?
				flags.precision : n, ' ', size);
		ft_print_elem(flags.precision, n, '0', size);
	}
	return (number);
}

void	ft_point_parsing_id(char *str, va_list args, int *size, t_flags flags)
{
	int	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, int);
	if (number == 0)
		ft_point_parsing_id_extends_2(flags, size);
	else
	{
		if (flags.blanks == 1 && flags.precision != -1)
			number = ft_point_parsing_id_extends(flags, number, size, n);
		else
		{
			if (number < 0)
			{
				ft_print_elem(flags.width, n + 1, ' ', size);
				ft_putchar('-', size);
				number = number * -1;
			}
			else
				ft_print_elem(flags.width, n, ' ', size);
		}
		ft_putnbr(number, size);
	}
}

void	ft_point_parsing(char *str, va_list args, int *size, t_flags flags)
{
	if (str[0] == 's')
		ft_digits_parsing_s(args, size, flags);
	else if (str[0] == 'c')
		ft_digits_parsing_c(args, size, flags);
	else if (str[0] == 'u')
		ft_digits_parsing_u(str, args, size, flags);
	else if (str[0] == 'd' || str[0] == 'i')
		ft_point_parsing_id(str, args, size, flags);
	else if (str[0] == 'x')
		ft_digits_parsing_hexa(str, args, size, flags);
	else if (str[0] == 'X')
		ft_digits_parsing_hexa_m(str, args, size, flags);
	else if (str[0] == 'p')
		ft_digits_parsing_adr(str, args, size, flags);
	else if (str[0] == '%')
		ft_digits_parsing_prc(size, flags);
	clear_struct(&flags);
}

void	ft_parse_point(char *str, va_list args, int *p, int *size)
{
	int			k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	flags.width = 0;
	k++;
	k += ft_fill_precision(args, &str[k], &flags);
	*p = *p + k;
	if (flags.precision < 0)
	{
		if (str[k] == 's')
		{
			if (flags.precision == -1)
				flags.precision = 0;
			ft_minus_parsing(str + k, args, size, flags);
		}
		else
			ft_point_parsing(str + k, args, size, flags);
	}
	else
		ft_point_parsing(str + k, args, size, flags);
}
