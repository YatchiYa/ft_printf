/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hexa_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:54:16 by yarab             #+#    #+#             */
/*   Updated: 2020/01/12 14:16:56 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_digits_parsing_hexa_m(char *str, va_list args,
		int *size, t_flags flags)
{
	unsigned int	number;
	int				n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned int);
	if (number == 0 && flags.precision == 0)
	{
		if (flags.is_width == '1' && flags.width < 0)
			flags.width *= -1;
		ft_print_elem(flags.precision, 0, '0', size);
		ft_print_elem(flags.width, flags.precision, ' ', size);
	}
	else
	{
		if (flags.is_prec == '1')
		{
			ft_print_elem(flags.width,
					flags.precision > n ? flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
		}
		else
			ft_print_elem(flags.width, n, ' ', size);
		ft_putadr_maj(number, size);
	}
}

void	ff_ddxxx(t_flags flags, int *size)
{
	if (flags.is_width == '1' && flags.width < 0)
		flags.width *= -1;
	if (flags.is_prec == '0')
	{
		ft_putchar('0', size);
		ft_print_elem(flags.width, 1, ' ', size);
	}
	else if (flags.precision < 0 && flags.is_prec == '1')
	{
		ft_putchar('0', size);
		ft_print_elem(flags.width, 1, ' ', size);
	}
	else if (flags.precision > 0)
	{
		ft_print_elem(flags.precision, 1, '0', size);
		ft_putchar('0', size);
		ft_print_elem(flags.width, flags.precision, ' ', size);
	}
	else
		ft_print_elem(flags.width, 0, ' ', size);
}

void	ft_minus_parse_hexa_m(char *str, va_list args,
		int *size, t_flags flags)
{
	unsigned int	number;
	int				n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned int);
	if (number == 0)
		ff_ddxxx(flags, size);
	else
	{
		if (flags.precision < 0)
			flags.precision = -1;
		if (flags.precision != -1)
		{
			ft_print_elem(flags.precision, n, '0', size);
			ft_putadr_maj(number, size);
			ft_print_elem(flags.width,
					flags.precision > n ?
					flags.precision : n, ' ', size);
		}
		else if (flags.precision == -1)
		{
			ft_putadr_maj(number, size);
			ft_print_elem(flags.width, n, ' ', size);
		}
	}
}

void	ff_zzx(t_flags flags, int *size)
{
	if (flags.is_width == '1' && flags.width < 0)
		flags.width *= -1;
	if (flags.is_prec == '0')
	{
		ft_print_elem(flags.width, 1, '0', size);
		ft_putchar('0', size);
	}
	else if (flags.precision < 0 && flags.is_prec == '1')
	{
		ft_print_elem(flags.width, 1, '0', size);
		ft_putchar('0', size);
	}
	else if (flags.precision == 0)
		ft_print_elem(flags.width, 0, ' ', size);
	else
	{
		ft_print_elem(flags.width, flags.precision, ' ', size);
		ft_print_elem(flags.precision, 1, '0', size);
		ft_putchar('0', size);
	}
}

void	ft_zero_parsing_hexa_m(char *str, va_list args,
		int *size, t_flags flags)
{
	unsigned int	number;
	int				n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned int);
	if (number == 0)
		ff_zzx(flags, size);
	else
	{
		if (flags.is_prec == '1')
		{
			if (flags.precision < 0)
				ft_print_elem(flags.width, flags.precision > n ?
						flags.precision : n, '0', size);
			else
				ft_print_elem(flags.width, flags.precision > n ?
						flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
		}
		else
			ft_print_elem(flags.width, n, '0', size);
		ft_putadr_maj(number, size);
	}
}
