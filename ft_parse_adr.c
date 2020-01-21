/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_adr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:33:54 by yarab             #+#    #+#             */
/*   Updated: 2020/01/12 13:54:20 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ff_xx(int *size, t_flags flags)
{
	ft_print_elem(flags.width, flags.precision + 2, ' ', size);
	ft_putstr("0x", size);
	ft_print_elem(flags.precision, 0, '0', size);
}

void	ff_dd(unsigned long number,
	int *size, t_flags flags, int n)
{
	ft_print_elem(flags.width, flags.precision + 2, ' ', size);
	ft_putstr("0x", size);
	ft_print_elem(flags.precision + 2, n, '0', size);
	ft_putadr(number, size);
}

void	ft_digits_parsing_adr(char *str, va_list args, int *size, t_flags flags)
{
	void			*adr;
	unsigned long	number;
	int				n;

	n = ft_str_length_format(str[0], args);
	adr = va_arg(args, void*);
	number = (unsigned long)(adr);
	if (flags.is_prec == '0' && flags.is_width == '0')
		ft_putstr("0x", size);
	else if (number == 0 && flags.is_prec == '1')
		ff_xx(size, flags);
	else
	{
		if (flags.is_prec == '1')
			ft_print_elem(flags.width, flags.precision > n ?
			flags.precision + 2 : n, ' ', size);
		else
			ft_print_elem(flags.width, n, ' ', size);
		ft_putstr("0x", size);
		if (flags.is_prec == '1')
			ft_print_elem(flags.precision + 2, n, '0', size);
		ft_putadr(number, size);
	}
}

void	ft_minus_parse_adr(char *str, va_list args, int *size, t_flags flags)
{
	void			*adr;
	unsigned long	number;
	int				n;

	n = ft_str_length_format(str[0], args);
	adr = va_arg(args, void*);
	number = (unsigned long)(adr);
	if (flags.is_prec == '1')
	{
		ft_print_elem(flags.precision, n, '0', size);
		ft_putstr("0x", size);
		ft_putadr(number, size);
		ft_print_elem(flags.width,
				flags.precision > n ? flags.precision : n, ' ', size);
	}
	else
	{
		ft_putstr("0x", size);
		ft_putadr(number, size);
		ft_print_elem(flags.width, n, ' ', size);
	}
}

void	ft_zero_parsing_adr(char *str, va_list args, int *size, t_flags flags)
{
	void			*adr;
	unsigned long	number;
	int				n;

	n = ft_str_length_format(str[0], args);
	adr = va_arg(args, void*);
	number = (unsigned long)(adr);
	ft_putstr("0x", size);
	if (flags.is_prec == '1')
	{
		ft_print_elem(flags.width,
				flags.precision > n ? flags.precision : n, ' ', size);
		ft_print_elem(flags.precision, n, '0', size);
	}
	else if (flags.precision == -1 && flags.blanks == 0)
		ft_print_elem(flags.width, n, '0', size);
	ft_putadr(number, size);
}
