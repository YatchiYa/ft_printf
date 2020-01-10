/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:03:55 by yarab             #+#    #+#             */
/*   Updated: 2020/01/10 12:05:41 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_parse_uint(va_list args, int *p)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	ft_putnbr_u(number, p);
}

void	ft_minus_parse_u(char *str, va_list args, int *size, t_flags flags)
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
		if (flags.blanks == 1 && flags.precision != -1)
		{
			ft_print_elem(flags.precision, n, '0', size);
			ft_putnbr_u(number, size);
			ft_print_elem(flags.width,
					flags.precision > n ? flags.precision : n, ' ', size);
		}
		else
		{
			ft_putnbr_u(number, size);
			ft_print_elem(flags.width, n, ' ', size);
		}
	}
}

void	ft_zero_parsing_u(char *str, va_list args, int *size, t_flags flags)
{
	unsigned int	number;
	int				n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned int);
	if (number == 0)
	{
		if (flags.is_width == '1' && flags.width < 0)
			flags.width *= -1;
		if (flags.precision < 0)
		{
			ft_print_elem(flags.width, 1, '0', size);
			ft_putchar('0', size);
		}
		else if (flags.precision > 0)
		{
			ft_print_elem(flags.width, flags.precision, ' ', size);
			ft_print_elem(flags.precision, 1, '0', size);
			ft_putchar('0', size);
		}
		else
			ft_print_elem(flags.width, 0, ' ', size);
	}
	else
	{
		if (flags.precision < 0)
			flags.precision = -1;
		if (flags.precision != -1)
		{
			ft_print_elem(flags.width,
					flags.precision > n ? flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
		}
		else if (flags.precision == -1)
			ft_print_elem(flags.width, n, '0', size);
		ft_putnbr_u(number, size);
	}
}

void	ft_digits_parsing_u(char *str, va_list args, int *size, t_flags flags)
{
	unsigned int	number;
	int				n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned int);
	if (number == 0)
	{
		if (flags.is_width == '1' && flags.width < 0)
			flags.width *= -1;
		if (flags.precision < 0)
		{
			ft_print_elem(flags.width, 1, ' ', size);
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
		ft_putnbr_u(number, size);
	}
}
