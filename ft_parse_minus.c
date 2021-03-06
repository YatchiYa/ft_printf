/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:57:02 by yarab             #+#    #+#             */
/*   Updated: 2020/01/12 14:34:00 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_minus_parse_id_extends_2(t_flags flags, int *size)
{
	if (flags.precision < 0)
	{
		ft_putchar('0', size);
		ft_print_elem(flags.width, 1, ' ', size);
	}
	else if (flags.precision == 0)
		ft_print_elem(flags.width, 0, ' ', size);
	else
	{
		ft_print_elem(flags.precision, 1, '0', size);
		ft_putchar('0', size);
		ft_print_elem(flags.width, flags.precision, ' ', size);
	}
}

void	xxff(t_flags flags, int number, int *size, int n)
{
	if (number < 0)
	{
		number != INT_MIN ? ft_putchar('-', size) : 0;
		number = number * -1;
		ft_putnbr(number, size);
		ft_print_elem(flags.width, n + 1, ' ', size);
	}
	else
	{
		ft_putnbr(number, size);
		ft_print_elem(flags.width, n, ' ', size);
	}
}

void	ft_minus_parse_id(char *str, va_list args, int *size, t_flags flags)
{
	int	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, int);
	if (number == 0)
		ft_minus_parse_id_extends_2(flags, size);
	else
	{
		if (flags.is_prec == '1')
			number = ft_minus_parse_id_extends(flags, number, size, n);
		else
			xxff(flags, number, size, n);
	}
}

void	ft_minus_parsing(char *str, va_list args, int *size, t_flags flags)
{
	if (str[0] == 'd' || str[0] == 'i')
		ft_minus_parse_id(str, args, size, flags);
	if (str[0] == 'u')
		ft_minus_parse_u(str, args, size, flags);
	if (str[0] == 'x')
		ft_minus_parse_hexa(str, args, size, flags);
	if (str[0] == 'X')
		ft_minus_parse_hexa_m(str, args, size, flags);
	if (str[0] == 'c')
		ft_minus_parse_c(args, size, flags);
	if (str[0] == 's')
		ft_minus_parse_str(args, size, flags);
	if (str[0] == 'p')
		ft_minus_parse_adr(str, args, size, flags);
	if (str[0] == '%')
		ft_minus_parse_prc(size, flags);
	clear_struct(&flags);
}

void	ft_parse_minus(char *str, va_list args, int *p, int *size)
{
	int			k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	while (str[k] == '-')
		k++;
	if (str[k] != '.')
	{
		k += ft_fill_width(args, &str[k], &flags);
	}
	if (str[k] == '.')
	{
		flags.precision = 0;
		k += ft_fill_precision(args, &str[k + 1], &flags) + 1;
		flags.is_prec = '1';
	}
	if (flags.width < 0 && flags.is_width == '1')
		flags.width *= -1;
	*p = *p + k + 1;
	ft_minus_parsing(str + k, args, size, flags);
}
