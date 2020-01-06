/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hexa_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:54:16 by yarab             #+#    #+#             */
/*   Updated: 2020/01/06 14:42:28 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_parse_hexa_m(va_list args, int *p)
{
	unsigned long	number;

	number = va_arg(args, unsigned long);
	ft_putadr_maj(number, p);
}

void	ft_digits_parsing_hexa_m(char *str, va_list args,
		int *size, t_flags flags)
{
	unsigned long	number;
	int				n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned long);
	if (number == 0 && flags.precision != -1)
	{
		ft_print_elem(flags.width, flags.precision, ' ', size);
		ft_print_elem(flags.precision, 0, '0', size);
	}
	else
	{
		if (flags.blanks == 1 && flags.precision != -1)
		{
			ft_print_elem(flags.width, flags.precision > n ?
					flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
		}
		else
			ft_print_elem(flags.width, n, ' ', size);
		ft_putadr_maj(number, size);
	}
}

void	ft_minus_parse_hexa_m(char *str, va_list args,
		int *size, t_flags flags)
{
	unsigned long	number;
	int				n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned long);
	if (number == 0 && flags.precision != -1)
	{
		ft_print_elem(flags.precision, 0, '0', size);
		ft_print_elem(flags.width, flags.precision, ' ', size);
	}
	else
	{
		if (flags.blanks == 1 && flags.precision != -1)
		{
			ft_print_elem(flags.precision, n, '0', size);
			ft_putadr_maj(number, size);
			ft_print_elem(flags.width,
					flags.precision > n ? flags.precision : n, ' ', size);
		}
		else
		{
			ft_putadr_maj(number, size);
			ft_print_elem(flags.width, n, ' ', size);
		}
	}
}

void	ft_zero_parsing_hexa_m(char *str, va_list args,
		int *size, t_flags flags)
{
	unsigned long	number;
	int				n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned long);
	if (flags.precision != -1)
	{
		ft_print_elem(flags.width,
				flags.precision > n ? flags.precision : n, ' ', size);
		ft_print_elem(flags.precision, n, '0', size);
	}
	else if (flags.precision == -1 && flags.blanks == 0)
		ft_print_elem(flags.width, n, '0', size);
	ft_putadr_maj(number, size);
}